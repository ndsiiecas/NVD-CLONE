NS_IMETHODIMP
CVE_2011_0084_VULN_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int calculate_a = 5;
int calculate_b = 0;
  if (!point)
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
calculate_b = 7 * calculate_a + 2;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
