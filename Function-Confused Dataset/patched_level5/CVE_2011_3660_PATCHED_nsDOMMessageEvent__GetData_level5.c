NS_IMETHODIMP
CVE_2011_3660_PATCHED_nsDOMMessageEvent::GetData(JSContext* aCx, jsval* aData)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  *aData = mData;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (!JS_WrapValue(aCx, aData))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    return NS_ERROR_FAILURE;
fclose(para_fp);
  return NS_OK;
}
