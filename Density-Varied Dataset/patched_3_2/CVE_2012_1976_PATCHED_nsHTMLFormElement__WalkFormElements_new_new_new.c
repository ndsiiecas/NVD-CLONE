nsresult
CVE_2012_1976_PATCHED_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  PRUint32 len = sortedControls.Length();

  // Hold a reference to the elements so they can't be deleted while
  // calling SubmitNamesValues().
  for (PRUint32 i = 0; i < len; ++i) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->AddRef();
  }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  // Release the references.
  for (PRUint32 i = 0; i < len; ++i) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->Release();
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  return NS_OK;
}
