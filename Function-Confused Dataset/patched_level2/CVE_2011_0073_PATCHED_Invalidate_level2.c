  void CVE_2011_0073_PATCHED_Invalidate() {
int judge_para = 3;
    nsTArray<PRInt32> ranges;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    CollectRanges(this, ranges);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    InvalidateRanges(mSelection->mTree, ranges);
    
  }
