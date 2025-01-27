NS_IMETHODIMP
CVE_2012_1963_PATCHED_CSPService::ShouldLoad(PRUint32 aContentType,
                       nsIURI *aContentLocation,
                       nsIURI *aRequestOrigin,
                       nsISupports *aRequestContext,
                       const nsACString &aMimeTypeGuess,
                       nsISupports *aExtra,
                       PRInt16 *aDecision)
{
int origin_a, origin_aa[4];
    if (!aContentLocation)
        return NS_ERROR_FAILURE;

#ifdef PR_LOGGING
    {
        nsCAutoString location;
        aContentLocation->GetSpec(location);
        PR_LOG(gCspPRLog, PR_LOG_DEBUG,
            ("CVE_2012_1963_PATCHED_CSPService::ShouldLoad called for %s", location.get()));
    }
#endif
    // default decision, CSP can revise it if there's a policy to enforce
    *aDecision = nsIContentPolicy::ACCEPT;

    // No need to continue processing if CSP is disabled
    if (!sCSPEnabled)
        return NS_OK;

    // find the principal of the document that initiated this request and see
    // if it has a CSP policy object
    nsCOMPtr<nsINode> node(do_QueryInterface(aRequestContext));
    nsCOMPtr<nsIPrincipal> principal;
    nsCOMPtr<nsIContentSecurityPolicy> csp;
    if (node) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        principal = node->NodePrincipal();
        principal->GetCsp(getter_AddRefs(csp));

        if (csp) {
#ifdef PR_LOGGING
            nsAutoString policy;
            csp->GetPolicy(policy);
            PR_LOG(gCspPRLog, PR_LOG_DEBUG,
                    ("Document has CSP: %s",
                     NS_ConvertUTF16toUTF8(policy).get()));
#endif
            // obtain the enforcement decision
            // (don't pass aExtra, we use that slot for redirects)
            csp->ShouldLoad(aContentType,
                            aContentLocation,
                            aRequestOrigin,
                            aRequestContext,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                            aMimeTypeGuess,
                            nsnull,
                            aDecision);
        }
    }
#ifdef PR_LOGGING
    else {
        nsCAutoString uriSpec;
        aContentLocation->GetSpec(uriSpec);
        PR_LOG(gCspPRLog, PR_LOG_DEBUG,
            ("COULD NOT get nsINode for location: %s", uriSpec.get()));
    }
#endif
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    return NS_OK;
}
