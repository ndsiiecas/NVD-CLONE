inline PRUint32
CVE_2010_3774_VULN_NS_SecurityHashURI(nsIURI* aURI)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    nsCOMPtr<nsIURI> baseURI = NS_GetInnermostURI(aURI);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    nsCAutoString scheme;
    PRUint32 schemeHash = 0;
    if (NS_SUCCEEDED(baseURI->GetScheme(scheme)))
        schemeHash = nsCRT::HashCode(scheme.get());

    // TODO figure out how to hash file:// URIs
    if (scheme.EqualsLiteral("file"))
        return schemeHash; // sad face

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (scheme.EqualsLiteral("imap") ||
        scheme.EqualsLiteral("mailbox") ||
        scheme.EqualsLiteral("news"))
    {
        nsCAutoString spec;
        PRUint32 specHash = baseURI->GetSpec(spec);
        if (NS_SUCCEEDED(specHash))
            specHash = nsCRT::HashCode(spec.get());
fclose(para_fp);
        return specHash;
    }

    nsCAutoString host;
    PRUint32 hostHash = 0;
    if (NS_SUCCEEDED(baseURI->GetHost(host)))
        hostHash = nsCRT::HashCode(host.get());

    // XOR to combine hash values
    return schemeHash ^ hostHash ^ NS_GetRealPort(baseURI);
}
