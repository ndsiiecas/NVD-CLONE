NS_IMETHODIMP CVE_2011_0083_VULN_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

  // immediately remove the new item from its current list
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  RemoveFromCurrentList(newItemSeg);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  // NOTE: the new item can never be the item we will be replacing now that we removed it from its current list beforehand
  InsertElementAt(newItemSeg, index);
  RemoveFromCurrentList(static_cast<nsSVGPathSeg*>(mSegments.ObjectAt(index+1)));
  NS_ADDREF(*_retval = newItem);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  return NS_OK;
}
