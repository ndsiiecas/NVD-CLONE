NS_IMETHODIMP
CVE_2011_0084_PATCHED_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
  if (!p)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    *_retval = metrics->GetCharNumAtPosition(point);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  return NS_OK;
}
