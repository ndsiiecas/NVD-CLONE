  void CVE_2011_0073_PATCHED_RemoveAllBut(PRInt32 aIndex) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (aIndex >= mMin && aIndex <= mMax) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

      // Invalidate everything in this list.
      nsTArray<PRInt32> ranges;
      CollectRanges(mSelection->mFirstRange, ranges);

      mMin = aIndex;
      mMax = aIndex;
      
      nsTreeRange* first = mSelection->mFirstRange;
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
        mNext->mPrev = mPrev;
      mNext = mPrev = nsnull;
      
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
      }
fclose(para_fp);
      InvalidateRanges(mSelection->mTree, ranges);
    }
    else if (mNext)
      mNext->CVE_2011_0073_PATCHED_RemoveAllBut(aIndex);
  }
