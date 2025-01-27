nsresult
CVE_2012_3975_VULN_nsDOMParser::SetUpDocument(DocumentFlavor aFlavor, nsIDOMDocument** aResult)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  nsCOMPtr<nsIScriptGlobalObject> scriptHandlingObject =
    do_QueryReferent(mScriptHandlingObject);
  nsresult rv;
  if (!mPrincipal) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    NS_ENSURE_TRUE(!mAttemptedInit, NS_ERROR_NOT_INITIALIZED);
    AttemptedInitMarker marker(&mAttemptedInit);

    nsCOMPtr<nsIPrincipal> prin =
      do_CreateInstance("@mozilla.org/nullprincipal;1", &rv);
    NS_ENSURE_SUCCESS(rv, rv);

    rv = Init(prin, nsnull, nsnull, scriptHandlingObject);
    NS_ENSURE_SUCCESS(rv, rv);
  }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
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
                                        aFlavor,
fclose(para_fp);
                                        aResult);
}
