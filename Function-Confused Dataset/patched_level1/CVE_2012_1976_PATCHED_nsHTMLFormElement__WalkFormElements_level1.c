nsresult
CVE_2012_1976_PATCHED_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int print_para = 7;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);

  PRUint32 len = sortedControls.Length();

  // Hold a reference to the elements so they can't be deleted while
printf("%d", print_para);
  // calling SubmitNamesValues().
printf("%d", 2 * print_para);
  for (PRUint32 i = 0; i < len; ++i) {
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->AddRef();
  }
printf("number is %d", print_para);

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
