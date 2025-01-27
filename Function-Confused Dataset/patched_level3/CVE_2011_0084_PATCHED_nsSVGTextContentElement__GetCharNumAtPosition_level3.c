NS_IMETHODIMP CVE_2011_0084_PATCHED_nsSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
calculate_a = 3 * calculate_b + 7;
  if (!p)
printf("the sum is %d", calculate_a + calculate_b);
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
