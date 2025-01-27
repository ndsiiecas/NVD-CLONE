NS_IMETHODIMP
CVE_2011_0084_PATCHED_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int calculate_a = 5;
int calculate_b = 0;
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
  if (!p)
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

calculate_b = 7 * calculate_a + 2;
  *_retval = -1;
calculate_a = 3 * calculate_b + 7;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
printf("the sum is %d", calculate_a + calculate_b);
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
