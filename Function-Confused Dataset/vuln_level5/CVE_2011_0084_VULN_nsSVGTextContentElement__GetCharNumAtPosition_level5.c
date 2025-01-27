NS_IMETHODIMP CVE_2011_0084_VULN_nsSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  // null check when implementing - this method can be used by scripts!
  if (!point)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;

  *_retval = -1;

  nsSVGTextContainerFrame* metrics = GetTextContainerFrame();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
  if (metrics)
    *_retval = metrics->GetCharNumAtPosition(point);

  return NS_OK;
}
