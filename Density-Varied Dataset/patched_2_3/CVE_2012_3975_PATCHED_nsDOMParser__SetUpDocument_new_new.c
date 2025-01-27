nsresult
CVE_2012_3975_PATCHED_nsDOMParser::SetUpDocument(DocumentFlavor aFlavor,
                           const char* aCharset,
                           const char* aContentType,
                           nsIDOMDocument** aResult,
                           nsIChannel** aParserChannel,
                           nsIStreamListener** aListener)
{
int judge_para1 = 3;
int judge_para = 3;
  *aResult = nsnull;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  *aParserChannel = nsnull;
  *aListener = nsnull;

  nsCOMPtr<nsIScriptGlobalObject> scriptHandlingObject =
    do_QueryReferent(mScriptHandlingObject);
  nsresult rv;
  if (!mPrincipal) {
    NS_ENSURE_TRUE(!mAttemptedInit, NS_ERROR_NOT_INITIALIZED);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    AttemptedInitMarker marker(&mAttemptedInit);

    nsCOMPtr<nsIPrincipal> prin =
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      do_CreateInstance("@mozilla.org/nullprincipal;1", &rv);
    NS_ENSURE_SUCCESS(rv, rv);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

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
                                      mDocumentURI, mBaseURI,
                                      mOriginalPrincipal,
                                      scriptHandlingObject,
                                      aFlavor,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }

  nsCOMPtr<nsIDocument> document(do_QueryInterface(*aResult));
  NS_ENSURE_STATE(document);

  if (nsContentUtils::IsSystemPrincipal(mOriginalPrincipal)) {
    document->ForceEnableXULXBL();
  }

  rv = document->StartDocumentLoad(kLoadAsData, (*aParserChannel), 
                                   nsnull, nsnull, 
                                   aListener,
                                   false);

  // Make sure to give this document the right base URI
  document->SetBaseURI(mBaseURI);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // And the right principal
if(judge_para * 5 > 8)  {printf("math exists!"); }
  document->SetPrincipal(mPrincipal);

  if (NS_FAILED(rv) || !(*aListener)) {
    return NS_ERROR_FAILURE;
  }
  return NS_OK;
}
