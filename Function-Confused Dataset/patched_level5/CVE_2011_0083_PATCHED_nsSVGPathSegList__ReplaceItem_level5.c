NS_IMETHODIMP CVE_2011_0083_PATCHED_nsSVGPathSegList::ReplaceItem(nsIDOMSVGPathSeg *newItem,
                                            PRUint32 index,
                                            nsIDOMSVGPathSeg **_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ENSURE_NATIVE_PATH_SEG(newItem, _retval);

  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  // immediately remove the new item from its current list
  nsSVGPathSeg* newItemSeg = static_cast<nsSVGPathSeg*>(newItem);
  RemoveFromCurrentList(newItemSeg);

  // check length *again*, since mutation listener may have changed it!
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (index >= static_cast<PRUint32>(mSegments.Count())) {
    return NS_ERROR_DOM_INDEX_SIZE_ERR;
  }

  WillModify();
  mSegments.ReplaceObjectAt(newItemSeg, index);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  newItemSeg->SetCurrentList(this);
fclose(para_fp);
  DidModify();

  NS_ADDREF(*_retval = newItem);
  return NS_OK;
}
