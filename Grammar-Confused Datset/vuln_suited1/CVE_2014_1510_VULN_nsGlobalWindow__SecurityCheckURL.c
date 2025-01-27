nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
  JSContext       *cxUsed;
  bool             freePass;
  nsCOMPtr<nsIURI> uri;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
    return NS_ERROR_FAILURE;

  return NS_OK;
}
