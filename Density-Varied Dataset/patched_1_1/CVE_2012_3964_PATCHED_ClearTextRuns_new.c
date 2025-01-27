  void CVE_2012_3964_PATCHED_ClearTextRuns() {
int judge_para = 3;
    ClearTextRun(nsnull, nsTextFrame::eInflated);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (HasFontSizeInflation()) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
      ClearTextRun(nsnull, nsTextFrame::eNotInflated);
    }
  }
