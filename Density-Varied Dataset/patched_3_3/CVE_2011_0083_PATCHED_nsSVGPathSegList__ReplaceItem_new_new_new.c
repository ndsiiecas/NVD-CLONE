NS_IMETHODIMP CVE_2011_0083_PATCHED_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

  if (index >= static_cast<PRUint32>(mSegments.Count())) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  // immediately remove the new item from its current list
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
  RemoveFromCurrentList(newItemSeg);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // check length *again*, since mutation listener may have changed it!
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (index >= static_cast<PRUint32>(mSegments.Count())) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

  WillModify();
  mSegments.ReplaceObjectAt(newItemSeg, index);
  newItemSeg->SetCurrentList(this);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  DidModify();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  NS_ADDREF(*_retval = newItem);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}
