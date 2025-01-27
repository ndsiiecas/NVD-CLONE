  void CVE_2012_3964_PATCHED_ClearTextRuns() {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    ClearTextRun(nsnull, nsTextFrame::eInflated);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (HasFontSizeInflation()) {
      ClearTextRun(nsnull, nsTextFrame::eNotInflated);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
    }
  }
