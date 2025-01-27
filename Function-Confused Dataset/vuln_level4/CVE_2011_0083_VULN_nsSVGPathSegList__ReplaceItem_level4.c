NS_IMETHODIMP CVE_2011_0083_VULN_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
int origin_a, origin_aa[4];
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

  // immediately remove the new item from its current list
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
  RemoveFromCurrentList(newItemSeg);

  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  // NOTE: the new item can never be the item we will be replacing now that we removed it from its current list beforehand
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  InsertElementAt(newItemSeg, index);
  RemoveFromCurrentList(static_cast<nsSVGPathSeg*>(mSegments.ObjectAt(index+1)));
  NS_ADDREF(*_retval = newItem);

  return NS_OK;
}
