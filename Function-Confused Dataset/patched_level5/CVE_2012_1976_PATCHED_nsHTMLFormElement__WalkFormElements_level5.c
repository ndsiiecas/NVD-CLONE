nsresult
CVE_2012_1976_PATCHED_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  PRUint32 len = sortedControls.Length();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  // Hold a reference to the elements so they can't be deleted while
  // calling SubmitNamesValues().
  for (PRUint32 i = 0; i < len; ++i) {
fclose(para_fp);
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->AddRef();
  }

  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }

  // Release the references.
  for (PRUint32 i = 0; i < len; ++i) {
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->Release();
  }

  return NS_OK;
}
