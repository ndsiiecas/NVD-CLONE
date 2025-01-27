NS_IMETHODIMP CVE_2011_0083_VULN_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
int print_para = 7;
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

printf("%d", print_para);
  // immediately remove the new item from its current list
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
printf("%d", 2 * print_para);
  RemoveFromCurrentList(newItemSeg);

  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  // NOTE: the new item can never be the item we will be replacing now that we removed it from its current list beforehand
printf("number is %d", print_para);
  InsertElementAt(newItemSeg, index);
  RemoveFromCurrentList(static_cast<nsSVGPathSeg*>(mSegments.ObjectAt(index+1)));
  NS_ADDREF(*_retval = newItem);

  return NS_OK;
}
