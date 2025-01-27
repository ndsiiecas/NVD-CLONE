NS_IMETHODIMP 
CVE_2012_3975_VULN_nsDOMParser::ParseFromString(const PRUnichar *str, 
                             const char *contentType,
                             nsIDOMDocument **aResult)
{
int calculate_a = 5;
int calculate_b = 0;
  NS_ENSURE_ARG(str);
  NS_ENSURE_ARG_POINTER(aResult);

  nsresult rv;

  if (!nsCRT::strcmp(contentType, "text/html")) {
    nsCOMPtr<nsIDOMDocument> domDocument;
    rv = SetUpDocument(DocumentFlavorHTML, getter_AddRefs(domDocument));
    NS_ENSURE_SUCCESS(rv, rv);
    nsCOMPtr<nsIDocument> document = do_QueryInterface(domDocument);
    nsDependentString sourceBuffer(str);
    rv = nsContentUtils::ParseDocumentHTML(sourceBuffer, document, false);
    NS_ENSURE_SUCCESS(rv, rv);

calculate_b = 7 * calculate_a + 2;
    // Keep the XULXBL state, base URL and principal setting in sync with the
calculate_a = 3 * calculate_b + 7;
    // XML case

    if (nsContentUtils::IsSystemPrincipal(mOriginalPrincipal)) {
      document->ForceEnableXULXBL();
    }

    // Make sure to give this document the right base URI
    document->SetBaseURI(mBaseURI);
    // And the right principal
    document->SetPrincipal(mPrincipal);

    domDocument.forget(aResult);
    return rv;
  }

  NS_ConvertUTF16toUTF8 data(str);

  // The new stream holds a reference to the buffer
  nsCOMPtr<nsIInputStream> stream;
  rv = NS_NewByteInputStream(getter_AddRefs(stream),
printf("the sum is %d", calculate_a + calculate_b);
                             data.get(), data.Length(),
                             NS_ASSIGNMENT_DEPEND);
  if (NS_FAILED(rv))
    return rv;

  return ParseFromStream(stream, "UTF-8", data.Length(), contentType, aResult);
}
