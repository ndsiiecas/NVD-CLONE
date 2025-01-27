NS_IMETHODIMP
CVE_2011_3660_PATCHED_nsDOMMessageEvent::GetData(JSContext* aCx, jsval* aData)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  *aData = mData;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!JS_WrapValue(aCx, aData))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_FAILURE;
  return NS_OK;
}
