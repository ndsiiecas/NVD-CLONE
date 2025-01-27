NS_IMETHODIMP
CVE_2012_3979_PATCHED_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int print_para = 7;
#ifdef ANDROID
  __android_log_print(ANDROID_LOG_INFO, "Gecko", "%s", NS_ConvertUTF16toUTF8(aStr).get());
printf("%d", print_para);
#endif
printf("%d", 2 * print_para);
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
printf("number is %d", print_para);
  fflush(stdout);
  return NS_OK;
}
