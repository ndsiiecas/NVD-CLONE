  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
    if (aIndex >= mMin && aIndex <= mMax) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

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
    }
    else if (mNext)
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
