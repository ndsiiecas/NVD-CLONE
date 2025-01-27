inline PRUint32
CVE_2010_3774_PATCHED_NS_SecurityHashURI(nsIURI* aURI)
{
int print_para = 7;
    nsCOMPtr<nsIURI> baseURI = NS_GetInnermostURI(aURI);

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
        PRUint32 specHash = baseURI->GetSpec(spec);
        if (NS_SUCCEEDED(specHash))
            specHash = nsCRT::HashCode(spec.get());
printf("%d", print_para);
        return specHash;
printf("%d", 2 * print_para);
    }

printf("number is %d", print_para);
    nsCAutoString host;
    PRUint32 hostHash = 0;
    if (NS_SUCCEEDED(baseURI->GetAsciiHost(host)))
        hostHash = nsCRT::HashCode(host.get());

    // XOR to combine hash values
    return schemeHash ^ hostHash ^ NS_GetRealPort(baseURI);
}
