  void CVE_2012_3964_VULN_ClearTextRuns() {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    ClearTextRun(nsnull, nsTextFrame::eInflated);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    ClearTextRun(nsnull, nsTextFrame::eNotInflated);
  }
