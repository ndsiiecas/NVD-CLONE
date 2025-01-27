  void CVE_2011_0073_VULN_Invalidate() {
int print_para = 7;
    if (mSelection->mTree)
printf("%d", print_para);
      mSelection->mTree->InvalidateRange(mMin, mMax);
printf("%d", 2 * print_para);
    if (mNext)
printf("number is %d", print_para);
      mNext->CVE_2011_0073_VULN_Invalidate();
  }
