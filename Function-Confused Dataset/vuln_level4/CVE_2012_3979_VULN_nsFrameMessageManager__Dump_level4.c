NS_IMETHODIMP
CVE_2012_3979_VULN_nsFrameMessageManager::Dump(const nsAString& aStr)
{
int origin_a, origin_aa[4];
#ifdef ANDROID
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  __android_log_print(ANDROID_LOG_INFO, "Gecko", NS_ConvertUTF16toUTF8(aStr).get());
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
#endif
  fputs(NS_ConvertUTF16toUTF8(aStr).get(), stdout);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  fflush(stdout);
  return NS_OK;
}
