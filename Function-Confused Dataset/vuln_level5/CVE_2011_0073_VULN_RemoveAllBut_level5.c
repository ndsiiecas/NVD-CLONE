  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (aIndex >= mMin && aIndex <= mMax) {

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

      mMin = aIndex;
      mMax = aIndex;
      
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
      nsTreeRange* first = mSelection->mFirstRange;
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
        mNext->mPrev = mPrev;
      mNext = mPrev = nsnull;
      
fclose(para_fp);
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
      }
    }
    else if (mNext)
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
