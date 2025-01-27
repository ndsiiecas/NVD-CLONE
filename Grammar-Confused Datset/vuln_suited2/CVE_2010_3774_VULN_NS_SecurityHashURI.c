inline PRUint32
CVE_2010_3774_VULN_NS_SecurityHashURI(nsIURI* aURI)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
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
        return specHash;
    }

    nsCAutoString host;
    PRUint32 hostHash = 0;
    if (NS_SUCCEEDED(baseURI->GetHost(host)))
        hostHash = nsCRT::HashCode(host.get());

    // XOR to combine hash values
    return schemeHash ^ hostHash ^ NS_GetRealPort(baseURI);
}
