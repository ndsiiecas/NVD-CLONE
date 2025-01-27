nsresult
CVE_2012_1976_VULN_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
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
  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  //
fclose(para_fp);
  PRUint32 len = sortedControls.Length();
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }

  return NS_OK;
}
