NS_IMETHODIMP CVE_2011_0084_PATCHED_nsSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
  if (!p)
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
