NS_IMETHODIMP 
CVE_2012_3975_VULN_nsDOMParser::ParseFromString(const PRUnichar *str, 
                             const char *contentType,
                             nsIDOMDocument **aResult)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_ARG(str);
  NS_ENSURE_ARG_POINTER(aResult);

  nsresult rv;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!nsCRT::strcmp(contentType, "text/html")) {
    nsCOMPtr<nsIDOMDocument> domDocument;
    rv = SetUpDocument(DocumentFlavorHTML, getter_AddRefs(domDocument));
    NS_ENSURE_SUCCESS(rv, rv);
    nsCOMPtr<nsIDocument> document = do_QueryInterface(domDocument);
    nsDependentString sourceBuffer(str);
    rv = nsContentUtils::ParseDocumentHTML(sourceBuffer, document, false);
    NS_ENSURE_SUCCESS(rv, rv);

    // Keep the XULXBL state, base URL and principal setting in sync with the
    // XML case

    if (nsContentUtils::IsSystemPrincipal(mOriginalPrincipal)) {
      document->ForceEnableXULXBL();
    }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    // Make sure to give this document the right base URI
    document->SetBaseURI(mBaseURI);
    // And the right principal
    document->SetPrincipal(mPrincipal);

    domDocument.forget(aResult);
    return rv;
  }

  NS_ConvertUTF16toUTF8 data(str);

  // The new stream holds a reference to the buffer
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  nsCOMPtr<nsIInputStream> stream;
  rv = NS_NewByteInputStream(getter_AddRefs(stream),
                             data.get(), data.Length(),
                             NS_ASSIGNMENT_DEPEND);
  if (NS_FAILED(rv))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    return rv;

if(judge_para * 5 > 8)  {printf("math exists!"); }
  return ParseFromStream(stream, "UTF-8", data.Length(), contentType, aResult);
}
