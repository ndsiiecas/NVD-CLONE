NS_IMETHODIMP
CVE_2012_3979_VULN_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
#ifdef ANDROID
  __android_log_print(ANDROID_LOG_INFO, "Gecko", NS_ConvertUTF16toUTF8(aStr).get());
#endif
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
calculate_a = 3 * calculate_b + 7;
  fflush(stdout);
printf("the sum is %d", calculate_a + calculate_b);
  return NS_OK;
}
