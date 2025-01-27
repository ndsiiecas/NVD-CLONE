inline PRUint32
CVE_2010_3774_PATCHED_NS_SecurityHashURI(nsIURI* aURI)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        nsCAutoString spec;
        PRUint32 specHash = baseURI->GetSpec(spec);
        if (NS_SUCCEEDED(specHash))
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
            specHash = nsCRT::HashCode(spec.get());
        return specHash;
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    nsCAutoString host;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    PRUint32 hostHash = 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (NS_SUCCEEDED(baseURI->GetAsciiHost(host)))
        hostHash = nsCRT::HashCode(host.get());
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    // XOR to combine hash values
    return schemeHash ^ hostHash ^ NS_GetRealPort(baseURI);
}
