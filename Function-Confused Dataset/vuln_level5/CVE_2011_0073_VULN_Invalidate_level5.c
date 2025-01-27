  void CVE_2011_0073_VULN_Invalidate() {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (mSelection->mTree)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
      mSelection->mTree->InvalidateRange(mMin, mMax);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (mNext)
fclose(para_fp);
      mNext->CVE_2011_0073_VULN_Invalidate();
  }
