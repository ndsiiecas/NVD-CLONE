NS_IMETHODIMP
CVE_2012_3979_VULN_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int print_para = 7;
printf("%d", print_para);
#ifdef ANDROID
  __android_log_print(ANDROID_LOG_INFO, "Gecko", NS_ConvertUTF16toUTF8(aStr).get());
#endif
printf("%d", 2 * print_para);
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
  fflush(stdout);
printf("number is %d", print_para);
  return NS_OK;
}
