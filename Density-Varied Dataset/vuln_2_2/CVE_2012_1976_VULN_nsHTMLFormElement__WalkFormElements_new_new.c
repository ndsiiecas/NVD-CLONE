nsresult
CVE_2012_1976_VULN_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
  PRUint32 len = sortedControls.Length();
  for (PRUint32 i = 0; i < len; ++i) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    // Tell the control to submit its name/value pairs to the submission
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }

  return NS_OK;
}
