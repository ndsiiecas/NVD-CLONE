nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int judge_para = 3;
  JSContext       *cxUsed;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &cxUsed))) {
    return NS_ERROR_FAILURE;
  }

  if (!cxUsed) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return NS_OK;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  AutoPushJSContext cx(cxUsed);

if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri))) {
    return NS_ERROR_FAILURE;
  }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  return NS_OK;
}
