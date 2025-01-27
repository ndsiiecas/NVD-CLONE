nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  JSContext       *cxUsed;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  bool             freePass;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  nsCOMPtr<nsIURI> uri;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
if(judge_para * 5 > 8)  {printf("math exists!"); }
        CheckLoadURIFromScript(cx, uri)))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_FAILURE;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  return NS_OK;
}
