nsresult
CVE_2012_1976_PATCHED_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int calculate_a = 5;
int calculate_b = 0;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);

  PRUint32 len = sortedControls.Length();

calculate_b = 7 * calculate_a + 2;
  // Hold a reference to the elements so they can't be deleted while
  // calling SubmitNamesValues().
  for (PRUint32 i = 0; i < len; ++i) {
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->AddRef();
calculate_a = 3 * calculate_b + 7;
  }
printf("the sum is %d", calculate_a + calculate_b);

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
