NS_IMETHODIMP
CVE_2011_0083_VULN_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  if (!newItem) {
    *_retval = nsnull;
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }

  nsresult rv = RemoveItem(index, _retval);
  if (NS_FAILED(rv))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    return rv;

fclose(para_fp);
  return InsertElementAt(newItem, index);
}
