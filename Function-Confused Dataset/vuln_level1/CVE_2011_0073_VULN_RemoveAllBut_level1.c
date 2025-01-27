  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
int print_para = 7;
    if (aIndex >= mMin && aIndex <= mMax) {

      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

      mMin = aIndex;
      mMax = aIndex;
      
printf("%d", print_para);
      nsTreeRange* first = mSelection->mFirstRange;
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
printf("%d", 2 * print_para);
        mNext->mPrev = mPrev;
      mNext = mPrev = nsnull;
printf("number is %d", print_para);
      
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
      }
    }
    else if (mNext)
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
