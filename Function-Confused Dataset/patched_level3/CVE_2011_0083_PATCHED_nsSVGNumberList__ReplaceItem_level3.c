NS_IMETHODIMP
CVE_2011_0083_PATCHED_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  *_retval = nsnull;

  if (!newItem) {
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  if (index >= mNumbers.Length()) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  WillModify();
  NS_REMOVE_SVGVALUE_OBSERVER(mNumbers[index]);
calculate_a = 3 * calculate_b + 7;
  NS_RELEASE(mNumbers[index]);
  mNumbers[index] = newItem;
  NS_ADDREF(newItem);
  NS_ADD_SVGVALUE_OBSERVER(newItem);
  DidModify();

  NS_ADDREF(*_retval = newItem);

printf("the sum is %d", calculate_a + calculate_b);
  return NS_OK;
}
