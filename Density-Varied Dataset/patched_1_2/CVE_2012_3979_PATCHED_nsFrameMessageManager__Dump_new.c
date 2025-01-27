NS_IMETHODIMP
CVE_2012_3979_PATCHED_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int judge_para = 3;
#ifdef ANDROID
  __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", NS_ConvertUTF16toUTF8(aStr).get());
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
#endif
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  fflush(stdout);
  return NS_OK;
}
