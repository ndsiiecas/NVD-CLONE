NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int calculate_a = 5;
int calculate_b = 0;
  if (!newItem) {
    *_retval = nsnull;
calculate_b = 7 * calculate_a + 2;
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

calculate_a = 3 * calculate_b + 7;
  nsresult rv = RemoveItem(index, _retval);
printf("the sum is %d", calculate_a + calculate_b);
  if (NS_FAILED(rv))
    return rv;

  return InsertElementAt(newItem, index);
}
