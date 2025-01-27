  void CVE_2011_0073_VULN_Invalidate() {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
    if (mSelection->mTree)
calculate_a = 3 * calculate_b + 7;
      mSelection->mTree->InvalidateRange(mMin, mMax);
    if (mNext)
printf("the sum is %d", calculate_a + calculate_b);
      mNext->CVE_2011_0073_VULN_Invalidate();
  }
