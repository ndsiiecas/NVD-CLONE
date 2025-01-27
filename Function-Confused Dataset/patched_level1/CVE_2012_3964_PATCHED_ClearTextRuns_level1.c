  void CVE_2012_3964_PATCHED_ClearTextRuns() {
int print_para = 7;
printf("%d", print_para);
    ClearTextRun(nsnull, nsTextFrame::eInflated);
    if (HasFontSizeInflation()) {
printf("%d", 2 * print_para);
printf("number is %d", print_para);
      ClearTextRun(nsnull, nsTextFrame::eNotInflated);
    }
  }
