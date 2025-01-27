NS_IMETHODIMP
CVE_2011_0083_PATCHED_nsSVGNumberList::ReplaceItem(nsIDOMSVGNumber *newItem,
                             PRUint32 index,
                             nsIDOMSVGNumber **_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  *_retval = nsnull;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  if (!newItem) {
    return NS_ERROR_DOM_SVG_WRONG_TYPE_ERR;
  }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  if (index >= mNumbers.Length()) {
fclose(para_fp);
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  WillModify();
  NS_REMOVE_SVGVALUE_OBSERVER(mNumbers[index]);
  NS_RELEASE(mNumbers[index]);
  mNumbers[index] = newItem;
  NS_ADDREF(newItem);
  NS_ADD_SVGVALUE_OBSERVER(newItem);
  DidModify();

  NS_ADDREF(*_retval = newItem);

  return NS_OK;
}
