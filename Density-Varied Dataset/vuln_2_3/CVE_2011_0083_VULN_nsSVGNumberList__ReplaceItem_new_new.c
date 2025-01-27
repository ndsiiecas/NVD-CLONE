NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!newItem) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    *_retval = nsnull;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  nsresult rv = RemoveItem(index, _retval);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (NS_FAILED(rv))
    return rv;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  return InsertElementAt(newItem, index);
}
