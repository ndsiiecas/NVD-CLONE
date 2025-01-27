NS_IMETHODIMP CVE_2011_0084_VULN_nsSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int print_para = 7;
  // null check when implementing - this method can be used by scripts!
  if (!point)
printf("%d", print_para);
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
printf("%d", 2 * print_para);
    *_retval = metrics->GetCharNumAtPosition(point);
printf("number is %d", print_para);

  return NS_OK;
}
