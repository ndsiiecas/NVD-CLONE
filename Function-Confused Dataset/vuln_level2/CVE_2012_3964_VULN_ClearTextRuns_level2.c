  void CVE_2012_3964_VULN_ClearTextRuns() {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    ClearTextRun(nsnull, nsTextFrame::eInflated);
    ClearTextRun(nsnull, nsTextFrame::eNotInflated);
  }
