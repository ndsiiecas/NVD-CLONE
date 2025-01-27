NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int origin_a, origin_aa[4];
  if (!newItem) {
    *_retval = nsnull;
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  nsresult rv = RemoveItem(index, _retval);
  if (NS_FAILED(rv))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    return rv;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  return InsertElementAt(newItem, index);
}
