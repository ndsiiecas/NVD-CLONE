nsresult
CVE_2012_3975_PATCHED_nsDOMParser::SetUpDocument(DocumentFlavor aFlavor,
                           const char* aCharset,
                           const char* aContentType,
                           nsIDOMDocument** aResult,
                           nsIChannel** aParserChannel,
                           nsIStreamListener** aListener)
{
int origin_a, origin_aa[4];
  *aResult = nsnull;
  *aParserChannel = nsnull;
  *aListener = nsnull;

  nsCOMPtr<nsIScriptGlobalObject> scriptHandlingObject =
    do_QueryReferent(mScriptHandlingObject);
  nsresult rv;
  if (!mPrincipal) {
    NS_ENSURE_TRUE(!mAttemptedInit, NS_ERROR_NOT_INITIALIZED);
    AttemptedInitMarker marker(&mAttemptedInit);

    nsCOMPtr<nsIPrincipal> prin =
      do_CreateInstance("@mozilla.org/nullprincipal;1", &rv);
    NS_ENSURE_SUCCESS(rv, rv);

    rv = Init(prin, nsnull, nsnull, scriptHandlingObject);
    NS_ENSURE_SUCCESS(rv, rv);
  }

  NS_ASSERTION(mPrincipal, "Must have principal by now");
  NS_ASSERTION(mDocumentURI, "Must have document URI by now");

  // Here we have to cheat a little bit...  Setting the base URI won't
  // work if the document has a null principal, so use
  // mOriginalPrincipal when creating the document, then reset the
  // principal.
  rv = nsContentUtils::CreateDocument(EmptyString(), EmptyString(), nsnull,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
                                      mDocumentURI, mBaseURI,
                                      mOriginalPrincipal,
                                      scriptHandlingObject,
                                      aFlavor,
                                      aResult);

  NS_ENSURE_SUCCESS(rv, rv);

  // Create a fake channel 
  NS_NewInputStreamChannel(aParserChannel, mDocumentURI, nsnull,
                           nsDependentCString(aContentType), nsnull);
  NS_ENSURE_STATE(*aParserChannel);

  // More principal-faking here 
  (*aParserChannel)->SetOwner(mOriginalPrincipal);

  if (aCharset) {
    (*aParserChannel)->SetContentCharset(nsDependentCString(aCharset));
  }

  nsCOMPtr<nsIDocument> document(do_QueryInterface(*aResult));
  NS_ENSURE_STATE(document);

  if (nsContentUtils::IsSystemPrincipal(mOriginalPrincipal)) {
    document->ForceEnableXULXBL();
  }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  rv = document->StartDocumentLoad(kLoadAsData, (*aParserChannel), 
                                   nsnull, nsnull, 
                                   aListener,
                                   false);

  // Make sure to give this document the right base URI
  document->SetBaseURI(mBaseURI);

  // And the right principal
  document->SetPrincipal(mPrincipal);

  if (NS_FAILED(rv) || !(*aListener)) {
    return NS_ERROR_FAILURE;
  }
  return NS_OK;
}
