NS_IMETHODIMP
CVE_2011_0084_VULN_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int print_para = 7;
printf("%d", print_para);
  if (!point)
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;
printf("%d", 2 * print_para);

printf("number is %d", print_para);
  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
