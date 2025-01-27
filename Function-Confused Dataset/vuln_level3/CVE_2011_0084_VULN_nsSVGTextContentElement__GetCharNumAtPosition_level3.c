NS_IMETHODIMP CVE_2011_0084_VULN_nsSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  // null check when implementing - this method can be used by scripts!
  if (!point)
calculate_a = 3 * calculate_b + 7;
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);
printf("the sum is %d", calculate_a + calculate_b);

  return NS_OK;
}
