NS_IMETHODIMP
CVE_2012_1963_VULN_CSPService::ShouldLoad(PRUint32 aContentType,
                       nsIURI *aContentLocation,
                       nsIURI *aRequestOrigin,
                       nsISupports *aRequestContext,
                       const nsACString &aMimeTypeGuess,
                       nsISupports *aExtra,
                       PRInt16 *aDecision)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (!aContentLocation)
        return NS_ERROR_FAILURE;

#ifdef PR_LOGGING
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    {
        nsCAutoString location;
        aContentLocation->GetSpec(location);
        PR_LOG(gCspPRLog, PR_LOG_DEBUG,
            ("CVE_2012_1963_VULN_CSPService::ShouldLoad called for %s", location.get()));
    }
#endif
    // default decision, CSP can revise it if there's a policy to enforce
    *aDecision = nsIContentPolicy::ACCEPT;

    // No need to continue processing if CSP is disabled
    if (!sCSPEnabled)
        return NS_OK;

    // find the principal of the document that initiated this request and see
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // if it has a CSP policy object
    nsCOMPtr<nsINode> node(do_QueryInterface(aRequestContext));
    nsCOMPtr<nsIPrincipal> principal;
    nsCOMPtr<nsIContentSecurityPolicy> csp;
    if (node) {
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
            csp->ShouldLoad(aContentType,
                            aContentLocation,
                            aRequestOrigin,
                            aRequestContext,
                            aMimeTypeGuess,
                            aExtra,
                            aDecision);
        }
    }
#ifdef PR_LOGGING
    else {
        nsCAutoString uriSpec;
        aContentLocation->GetSpec(uriSpec);
fclose(para_fp);
        PR_LOG(gCspPRLog, PR_LOG_DEBUG,
            ("COULD NOT get nsINode for location: %s", uriSpec.get()));
    }
#endif

    return NS_OK;
}
