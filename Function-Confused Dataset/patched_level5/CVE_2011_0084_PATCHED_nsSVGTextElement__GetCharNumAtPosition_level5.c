NS_IMETHODIMP
CVE_2011_0084_PATCHED_nsSVGTextElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsCOMPtr<DOMSVGPoint> p = do_QueryInterface(point);
  if (!p)
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);
fclose(para_fp);

  return NS_OK;
}
