  void CVE_2011_0073_PATCHED_RemoveAllBut(PRInt32 aIndex) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    if (aIndex >= mMin && aIndex <= mMax) {

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
      InvalidateRanges(mSelection->mTree, ranges);
    }
    else if (mNext)
      mNext->CVE_2011_0073_PATCHED_RemoveAllBut(aIndex);
  }
