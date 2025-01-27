NS_IMETHODIMP
CVE_2011_0083_PATCHED_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int judge_para1 = 3;
int judge_para = 3;
  *_retval = nsnull;

  if (!newItem) {
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  if (index >= mNumbers.Length()) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  }

  WillModify();
  NS_REMOVE_SVGVALUE_OBSERVER(mNumbers[index]);
  NS_RELEASE(mNumbers[index]);
  mNumbers[index] = newItem;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ADDREF(newItem);
  NS_ADD_SVGVALUE_OBSERVER(newItem);
  DidModify();

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  NS_ADDREF(*_retval = newItem);

  return NS_OK;
}
