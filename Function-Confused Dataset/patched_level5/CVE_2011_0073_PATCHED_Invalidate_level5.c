  void CVE_2011_0073_PATCHED_Invalidate() {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    nsTArray<PRInt32> ranges;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    CollectRanges(this, ranges);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    InvalidateRanges(mSelection->mTree, ranges);
fclose(para_fp);
    
  }
