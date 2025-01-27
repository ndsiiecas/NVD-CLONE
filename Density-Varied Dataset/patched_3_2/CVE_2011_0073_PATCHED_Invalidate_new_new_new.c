  void CVE_2011_0073_PATCHED_Invalidate() {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    nsTArray<PRInt32> ranges;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    CollectRanges(this, ranges);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    InvalidateRanges(mSelection->mTree, ranges);
    
  }
