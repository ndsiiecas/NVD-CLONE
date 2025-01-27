NS_IMETHODIMP CVE_2011_0073_VULN_nsTreeSelection::RangedSelect(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aAugment)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  PRBool single;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsresult rv = GetSingle(&single);
  if (NS_FAILED(rv))
    return rv;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  if ((mFirstRange || (aStartIndex != aEndIndex)) && single)
    return NS_OK;

  if (!aAugment) {
    // Clear our selection.
    if (mFirstRange) {
        mFirstRange->Invalidate();
        delete mFirstRange;
    }
  }

  if (aStartIndex == -1) {
    if (mShiftSelectPivot != -1)
      aStartIndex = mShiftSelectPivot;
    else if (mCurrentIndex != -1)
      aStartIndex = mCurrentIndex;
    else
      aStartIndex = aEndIndex;
  }

  mShiftSelectPivot = aStartIndex;
  rv = SetCurrentIndex(aEndIndex);
  if (NS_FAILED(rv))
    return rv;
  
  PRInt32 start = aStartIndex < aEndIndex ? aStartIndex : aEndIndex;
  PRInt32 end = aStartIndex < aEndIndex ? aEndIndex : aStartIndex;

  if (aAugment && mFirstRange) {
    // We need to remove all the items within our selected range from the selection,
    // and then we insert our new range into the list.
    nsresult rv = mFirstRange->RemoveRange(start, end);
fclose(para_fp);
    if (NS_FAILED(rv))
      return rv;
  }

  nsTreeRange* range = new nsTreeRange(this, start, end);
  if (!range)
    return NS_ERROR_OUT_OF_MEMORY;

  range->Invalidate();

  if (aAugment && mFirstRange)
    mFirstRange->Insert(range);
  else
    mFirstRange = range;

  FireOnSelectHandler();

  return NS_OK;
}
