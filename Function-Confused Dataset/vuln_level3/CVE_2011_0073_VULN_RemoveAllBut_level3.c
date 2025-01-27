  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
int calculate_a = 5;
int calculate_b = 0;
    if (aIndex >= mMin && aIndex <= mMax) {

      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

      mMin = aIndex;
      mMax = aIndex;
      
      nsTreeRange* first = mSelection->mFirstRange;
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
calculate_b = 7 * calculate_a + 2;
        mNext->mPrev = mPrev;
      mNext = mPrev = nsnull;
      
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
calculate_a = 3 * calculate_b + 7;
      }
    }
    else if (mNext)
printf("the sum is %d", calculate_a + calculate_b);
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
