nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  JSContext       *cxUsed;
  nsCOMPtr<nsIURI> uri;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &cxUsed))) {
    return NS_ERROR_FAILURE;
  }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!cxUsed) {
    return NS_OK;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  }

  AutoPushJSContext cx(cxUsed);

  if (NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri))) {
    return NS_ERROR_FAILURE;
  }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}
