  void CVE_2011_0073_VULN_RemoveAllBut(PRInt32 aIndex) {
int judge_para = 3;
    if (aIndex >= mMin && aIndex <= mMax) {

      // Invalidate everything in this list.
      mSelection->mFirstRange->Invalidate();

      mMin = aIndex;
      mMax = aIndex;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      
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
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    else if (mNext)
      mNext->CVE_2011_0073_VULN_RemoveAllBut(aIndex);
  }
