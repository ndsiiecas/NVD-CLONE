  void CVE_2012_3964_PATCHED_ClearTextRuns() {
int calculate_a = 5;
int calculate_b = 0;
    ClearTextRun(nsnull, nsTextFrame::eInflated);
calculate_b = 7 * calculate_a + 2;
    if (HasFontSizeInflation()) {
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
      ClearTextRun(nsnull, nsTextFrame::eNotInflated);
    }
  }
