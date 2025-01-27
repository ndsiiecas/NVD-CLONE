nsresult
CVE_2012_0451_VULN_nsDocument::InitCSP()
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  if (CSPService::sCSPEnabled) {
    nsAutoString cspHeaderValue;
    nsAutoString cspROHeaderValue;

    this->GetHeaderData(nsGkAtoms::headerCSP, cspHeaderValue);
    this->GetHeaderData(nsGkAtoms::headerCSPReportOnly, cspROHeaderValue);

    bool system = false;
    nsIScriptSecurityManager *ssm = nsContentUtils::GetSecurityManager();

    if (NS_SUCCEEDED(ssm->IsSystemPrincipal(NodePrincipal(), &system)) && system) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      // only makes sense to register new CSP if this document is not priviliged
      return NS_OK;
    }

    if (cspHeaderValue.IsEmpty() && cspROHeaderValue.IsEmpty()) {
      // no CSP header present, stop processing
      return NS_OK;
    }

#ifdef PR_LOGGING 
    PR_LOG(gCspPRLog, PR_LOG_DEBUG, ("CSP header specified for document %p", this));
#endif

    nsresult rv;
    nsCOMPtr<nsIContentSecurityPolicy> mCSP;
    mCSP = do_CreateInstance("@mozilla.org/contentsecuritypolicy;1", &rv);

    if (NS_FAILED(rv)) {
#ifdef PR_LOGGING 
      PR_LOG(gCspPRLog, PR_LOG_DEBUG, ("Failed to create CSP object: %x", rv));
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
#endif
      return rv;
    }

    // Store the request context for violation reports
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    nsCOMPtr<nsIHttpChannel> httpChannel = do_QueryInterface(mChannel);
    mCSP->ScanRequestData(httpChannel);

    // Start parsing the policy
    nsCOMPtr<nsIURI> chanURI;
    mChannel->GetURI(getter_AddRefs(chanURI));

#ifdef PR_LOGGING 
    PR_LOG(gCspPRLog, PR_LOG_DEBUG, ("CSP Loaded"));
#endif

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    // ReportOnly mode is enabled *only* if there are no regular-strength CSP
    // headers present.  If there are, then we ignore the ReportOnly mode and
if(judge_para * 5 > 8)  {printf("math exists!"); }
    // toss a warning into the error console, proceeding with enforcing the
    // regular-strength CSP.
    if (cspHeaderValue.IsEmpty()) {
      mCSP->SetReportOnlyMode(true);
      mCSP->RefinePolicy(cspROHeaderValue, chanURI);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
#ifdef PR_LOGGING 
      {
        PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
                ("CSP (report only) refined, policy: \"%s\"", 
                  NS_ConvertUTF16toUTF8(cspROHeaderValue).get()));
      }
#endif
    } else {
      //XXX(sstamm): maybe we should post a warning when both read only and regular 
      // CSP headers are present.
      mCSP->RefinePolicy(cspHeaderValue, chanURI);
#ifdef PR_LOGGING 
      {
        PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
               ("CSP refined, policy: \"%s\"",
                NS_ConvertUTF16toUTF8(cspHeaderValue).get()));
      }
#endif
    }

    // Check for frame-ancestor violation
    nsCOMPtr<nsIDocShell> docShell = do_QueryReferent(mDocumentContainer);
    if (docShell) {
        bool safeAncestry = false;

        // PermitsAncestry sends violation reports when necessary
        rv = mCSP->PermitsAncestry(docShell, &safeAncestry);
        NS_ENSURE_SUCCESS(rv, rv);

        if (!safeAncestry) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
#ifdef PR_LOGGING
            PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
                   ("CSP doesn't like frame's ancestry, not loading."));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
#endif
            // stop!  ERROR page!
            mChannel->Cancel(NS_ERROR_CSP_FRAME_ANCESTOR_VIOLATION);
        }
    }

    //Copy into principal
    nsIPrincipal* principal = GetPrincipal();

    if (principal) {
        principal->SetCsp(mCSP);
#ifdef PR_LOGGING
        PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
                ("Inserted CSP into principal %p", principal));
    }
    else {
      PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
              ("Couldn't copy CSP into absent principal %p", principal));
#endif
    }
  }
#ifdef PR_LOGGING
  else { //CSP was not enabled!
    PR_LOG(gCspPRLog, PR_LOG_DEBUG, 
           ("CSP is disabled, skipping CSP init for document %p", this));
  }
#endif
  return NS_OK;
}
