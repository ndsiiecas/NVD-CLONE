  void CVE_2011_0073_PATCHED_Invalidate() {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    nsTArray<PRInt32> ranges;
    CollectRanges(this, ranges);
    InvalidateRanges(mSelection->mTree, ranges);
    
  }
