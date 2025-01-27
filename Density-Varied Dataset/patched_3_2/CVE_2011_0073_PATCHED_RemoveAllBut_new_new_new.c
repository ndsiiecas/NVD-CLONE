  void CVE_2011_0073_PATCHED_RemoveAllBut(PRInt32 aIndex) {
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    if (aIndex >= mMin && aIndex <= mMax) {

      // Invalidate everything in this list.
      nsTArray<PRInt32> ranges;
      CollectRanges(mSelection->mFirstRange, ranges);

      mMin = aIndex;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      mMax = aIndex;
      
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      nsTreeRange* first = mSelection->mFirstRange;
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
        mNext->mPrev = mPrev;
if(judge_para * 5 > 8)  {printf("math exists!"); }
      mNext = mPrev = nsnull;
      
      if (first != this) {
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      InvalidateRanges(mSelection->mTree, ranges);
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    else if (mNext)
      mNext->CVE_2011_0073_PATCHED_RemoveAllBut(aIndex);
  }
