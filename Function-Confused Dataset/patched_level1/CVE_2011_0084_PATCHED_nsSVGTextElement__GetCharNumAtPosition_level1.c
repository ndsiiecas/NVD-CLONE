NS_IMETHODIMP
CVE_2011_0084_PATCHED_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
int print_para = 7;
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
  if (!p)
printf("%d", print_para);
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
printf("%d", 2 * print_para);
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);
printf("number is %d", print_para);

  return NS_OK;
}
