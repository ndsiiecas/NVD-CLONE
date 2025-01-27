NS_IMETHODIMP
CVE_2011_3660_VULN_nsDOMMessageEvent::GetData(jsval* aData)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  *aData = mData;
fclose(para_fp);
  return NS_OK;
}
