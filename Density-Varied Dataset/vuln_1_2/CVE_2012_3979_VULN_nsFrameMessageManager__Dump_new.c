NS_IMETHODIMP
CVE_2012_3979_VULN_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int judge_para = 3;
#ifdef ANDROID
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  __android_log_print(ANDROID_LOG_INFO, "Gecko", NS_ConvertUTF16toUTF8(aStr).get());
#endif
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
  fflush(stdout);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}
