NS_IMETHODIMP CVE_2011_0073_PATCHED_nsTreeSelection::RangedSelect(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aAugment)
{
int origin_a, origin_aa[4];
  PRBool single;
  nsresult rv = GetSingle(&single);
  if (NS_FAILED(rv))
    return rv;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  if ((mFirstRange || (aStartIndex != aEndIndex)) && single)
    return NS_OK;

  if (!aAugment) {
    // Clear our selection.
    if (mFirstRange) {
        mFirstRange->Invalidate();
        delete mFirstRange;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        mFirstRange = nsnull;
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
    if (NS_FAILED(rv))
      return rv;
  }

  nsTreeRange* range = new nsTreeRange(this, start, end);
  if (!range)
    return NS_ERROR_OUT_OF_MEMORY;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  range->Invalidate();

  if (aAugment && mFirstRange)
    mFirstRange->Insert(range);
  else
    mFirstRange = range;

  FireOnSelectHandler();

  return NS_OK;
}
