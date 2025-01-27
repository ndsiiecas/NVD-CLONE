  void CVE_2011_0073_PATCHED_Invalidate() {
int calculate_a = 5;
int calculate_b = 0;
    nsTArray<PRInt32> ranges;
calculate_b = 7 * calculate_a + 2;
    CollectRanges(this, ranges);
    InvalidateRanges(mSelection->mTree, ranges);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    
  }
