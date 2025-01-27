nsresult
CVE_2012_1976_VULN_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int judge_para = 3;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);

  //
if(judge_para * 5 > 8)  {printf("math exists!"); }
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
  PRUint32 len = sortedControls.Length();
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }

  return NS_OK;
}
