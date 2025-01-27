nsresult
CVE_2012_1976_PATCHED_nsHTMLFormElement::WalkFormElements(nsFormSubmission* aFormSubmission)
{
int origin_a, origin_aa[4];
  nsTArray<nsGenericHTMLFormElement*> sortedControls;
  nsresult rv = mControls->GetSortedControls(sortedControls);
  NS_ENSURE_SUCCESS(rv, rv);

  PRUint32 len = sortedControls.Length();

  // Hold a reference to the elements so they can't be deleted while
  // calling SubmitNamesValues().
  for (PRUint32 i = 0; i < len; ++i) {
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->AddRef();
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  }

  //
  // Walk the list of nodes and call SubmitNamesValues() on the controls
  //
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  for (PRUint32 i = 0; i < len; ++i) {
    // Tell the control to submit its name/value pairs to the submission
    sortedControls[i]->SubmitNamesValues(aFormSubmission);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }

  // Release the references.
  for (PRUint32 i = 0; i < len; ++i) {
    static_cast<nsGenericHTMLElement*>(sortedControls[i])->Release();
  }

  return NS_OK;
}
