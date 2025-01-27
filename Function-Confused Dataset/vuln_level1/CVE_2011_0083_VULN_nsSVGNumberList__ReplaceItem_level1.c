NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int print_para = 7;
  if (!newItem) {
printf("%d", print_para);
    *_retval = nsnull;
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }
printf("%d", 2 * print_para);

  nsresult rv = RemoveItem(index, _retval);
printf("number is %d", print_para);
  if (NS_FAILED(rv))
    return rv;

  return InsertElementAt(newItem, index);
}
