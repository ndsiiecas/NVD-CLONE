NS_IMETHODIMP
CVE_2012_3979_PATCHED_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
#ifdef ANDROID
  __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", NS_ConvertUTF16toUTF8(aStr).get());
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
#endif
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  fflush(stdout);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}
