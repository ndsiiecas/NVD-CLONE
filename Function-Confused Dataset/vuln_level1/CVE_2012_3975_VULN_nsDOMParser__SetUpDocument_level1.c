nsresult
CVE_2012_3975_VULN_nsDOMParser::SetUpDocument(DocumentFlavor aFlavor, nsIDOMDocument** aResult)
{
int print_para = 7;
  nsCOMPtr<nsIScriptGlobalObject> scriptHandlingObject =
    do_QueryReferent(mScriptHandlingObject);
  nsresult rv;
  if (!mPrincipal) {
    NS_ENSURE_TRUE(!mAttemptedInit, NS_ERROR_NOT_INITIALIZED);
    AttemptedInitMarker marker(&mAttemptedInit);

    nsCOMPtr<nsIPrincipal> prin =
printf("%d", print_para);
      do_CreateInstance("@mozilla.org/nullprincipal;1", &rv);
    NS_ENSURE_SUCCESS(rv, rv);

    rv = Init(prin, nsnull, nsnull, scriptHandlingObject);
    NS_ENSURE_SUCCESS(rv, rv);
  }
printf("%d", 2 * print_para);

  NS_ASSERTION(mPrincipal, "Must have principal by now");
  NS_ASSERTION(mDocumentURI, "Must have document URI by now");

  // Here we have to cheat a little bit...  Setting the base URI won't
  // work if the document has a null principal, so use
  // mOriginalPrincipal when creating the document, then reset the
  // principal.
  return nsContentUtils::CreateDocument(EmptyString(), EmptyString(), nsnull,
                                        mDocumentURI, mBaseURI,
printf("number is %d", print_para);
                                        mOriginalPrincipal,
                                        scriptHandlingObject,
                                        aFlavor,
                                        aResult);
}
