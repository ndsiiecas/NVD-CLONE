inline PRUint32
CVE_2010_3774_PATCHED_NS_SecurityHashURI(nsIURI* aURI)
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

    if (scheme.EqualsLiteral("imap") ||
        scheme.EqualsLiteral("mailbox") ||
        scheme.EqualsLiteral("news"))
    {
        nsCAutoString spec;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        PRUint32 specHash = baseURI->GetSpec(spec);
fclose(para_fp);
        if (NS_SUCCEEDED(specHash))
            specHash = nsCRT::HashCode(spec.get());
        return specHash;
    }

    nsCAutoString host;
    PRUint32 hostHash = 0;
    if (NS_SUCCEEDED(baseURI->GetAsciiHost(host)))
        hostHash = nsCRT::HashCode(host.get());

    // XOR to combine hash values
    return schemeHash ^ hostHash ^ NS_GetRealPort(baseURI);
}
