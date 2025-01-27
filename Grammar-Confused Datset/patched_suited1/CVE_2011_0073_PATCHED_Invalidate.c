  void CVE_2011_0073_PATCHED_Invalidate() {
    nsTArray<PRInt32> ranges;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    CollectRanges(this, ranges);
    InvalidateRanges(mSelection->mTree, ranges);
    
  }
