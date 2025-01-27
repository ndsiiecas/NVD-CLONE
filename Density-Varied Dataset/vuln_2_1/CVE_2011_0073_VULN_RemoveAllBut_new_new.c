  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
int judge_para1 = 3;
int judge_para = 3;
    if (aIndex >= mMin && aIndex <= mMax) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

      mMin = aIndex;
      mMax = aIndex;
      
      nsTreeRange* first = mSelection->mFirstRange;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      if (mPrev)
        mPrev->mNext = mNext;
      if (mNext)
        mNext->mPrev = mPrev;
      mNext = mPrev = nsnull;
      
      if (first != this) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        delete mSelection->mFirstRange;
        mSelection->mFirstRange = this;
      }
    }
    else if (mNext)
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
