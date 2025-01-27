NS_IMETHODIMP
CVE_2011_0083_PATCHED_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int print_para = 7;
  *_retval = nsnull;

  if (!newItem) {
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  if (index >= mNumbers.Length()) {
printf("%d", print_para);
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  WillModify();
  NS_REMOVE_SVGVALUE_OBSERVER(mNumbers[index]);
  NS_RELEASE(mNumbers[index]);
  mNumbers[index] = newItem;
  NS_ADDREF(newItem);
  NS_ADD_SVGVALUE_OBSERVER(newItem);
  DidModify();

  NS_ADDREF(*_retval = newItem);
printf("%d", 2 * print_para);

printf("number is %d", print_para);
  return NS_OK;
}
