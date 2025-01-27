nsresult
CVE_2012_3975_VULN_nsDOMParser::SetUpDocument(DocumentFlavor aFlavor, nsIDOMDocument** aResult)
{
int judge_para = 3;
  nsCOMPtr<nsIScriptGlobalObject> scriptHandlingObject =
    do_QueryReferent(mScriptHandlingObject);
  nsresult rv;
  if (!mPrincipal) {
    NS_ENSURE_TRUE(!mAttemptedInit, NS_ERROR_NOT_INITIALIZED);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    AttemptedInitMarker marker(&mAttemptedInit);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    nsCOMPtr<nsIPrincipal> prin =
      do_CreateInstance("@mozilla.org/nullprincipal;1", &rv);
    NS_ENSURE_SUCCESS(rv, rv);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    rv = Init(prin, nsnull, nsnull, scriptHandlingObject);
    NS_ENSURE_SUCCESS(rv, rv);
  }

  NS_ASSERTION(mPrincipal, "Must have principal by now");
  NS_ASSERTION(mDocumentURI, "Must have document URI by now");

  // Here we have to cheat a little bit...  Setting the base URI won't
  // work if the document has a null principal, so use
  // mOriginalPrincipal when creating the document, then reset the
  // principal.
  return nsContentUtils::CreateDocument(EmptyString(), EmptyString(), nsnull,
                                        mDocumentURI, mBaseURI,
                                        mOriginalPrincipal,
                                        scriptHandlingObject,
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                        aFlavor,
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                        aResult);
}
