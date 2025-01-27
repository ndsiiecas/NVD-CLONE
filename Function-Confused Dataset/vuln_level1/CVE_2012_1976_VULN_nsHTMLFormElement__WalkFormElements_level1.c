nsresult
CVE_2012_1976_VULN_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int print_para = 7;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);

  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
printf("%d", print_para);
printf("%d", 2 * print_para);
  PRUint32 len = sortedControls.Length();
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }

printf("number is %d", print_para);
  return NS_OK;
}
