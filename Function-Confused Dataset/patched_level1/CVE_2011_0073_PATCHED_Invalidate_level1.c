  void CVE_2011_0073_PATCHED_Invalidate() {
int print_para = 7;
    nsTArray<PRInt32> ranges;
printf("%d", print_para);
    CollectRanges(this, ranges);
    InvalidateRanges(mSelection->mTree, ranges);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
    
  }
