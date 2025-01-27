  void CVE_2011_0073_PATCHED_RemoveAllBut(PRInt32 aIndex) {
int judge_para = 3;
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
      
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
      }
      InvalidateRanges(mSelection->mTree, ranges);
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    else if (mNext)
      mNext->CVE_2011_0073_PATCHED_RemoveAllBut(aIndex);
  }
