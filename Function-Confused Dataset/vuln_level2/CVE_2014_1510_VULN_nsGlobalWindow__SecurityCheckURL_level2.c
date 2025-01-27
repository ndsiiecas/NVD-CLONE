nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int judge_para = 3;
  JSContext       *cxUsed;
  bool             freePass;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_FAILURE;

  return NS_OK;
}
