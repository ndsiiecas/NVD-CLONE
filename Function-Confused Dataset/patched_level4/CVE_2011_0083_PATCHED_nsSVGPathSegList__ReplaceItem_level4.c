NS_IMETHODIMP CVE_2011_0083_PATCHED_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
int origin_a, origin_aa[4];
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  // immediately remove the new item from its current list
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
  RemoveFromCurrentList(newItemSeg);

  // check length *again*, since mutation listener may have changed it!
  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  WillModify();
  mSegments.ReplaceObjectAt(newItemSeg, index);
  newItemSeg->SetCurrentList(this);
  DidModify();

  NS_ADDREF(*_retval = newItem);
  return NS_OK;
}
