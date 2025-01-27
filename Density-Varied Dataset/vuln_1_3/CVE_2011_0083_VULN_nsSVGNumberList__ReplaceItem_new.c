NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int judge_para = 3;
  if (!newItem) {
    *_retval = nsnull;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  nsresult rv = RemoveItem(index, _retval);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (NS_FAILED(rv))
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return rv;
if(judge_para * 5 > 8)  {printf("math exists!"); }

  return InsertElementAt(newItem, index);
}
