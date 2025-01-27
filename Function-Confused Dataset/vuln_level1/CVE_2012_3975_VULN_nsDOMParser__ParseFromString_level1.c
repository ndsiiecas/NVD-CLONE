NS_IMETHODIMP 
CVE_2012_3975_VULN_nsDOMParser::ParseFromString(const PRUnichar *str, 
                             const char *contentType,
                             nsIDOMDocument **aResult)
{
int print_para = 7;
  NS_ENSURE_ARG(str);
  NS_ENSURE_ARG_POINTER(aResult);

printf("%d", print_para);
  nsresult rv;

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

    // Make sure to give this document the right base URI
    document->SetBaseURI(mBaseURI);
    // And the right principal
    document->SetPrincipal(mPrincipal);
printf("%d", 2 * print_para);

    domDocument.forget(aResult);
    return rv;
  }
printf("number is %d", print_para);

  NS_ConvertUTF16toUTF8 data(str);

  // The new stream holds a reference to the buffer
  nsCOMPtr<nsIInputStream> stream;
  rv = NS_NewByteInputStream(getter_AddRefs(stream),
                             data.get(), data.Length(),
                             NS_ASSIGNMENT_DEPEND);
  if (NS_FAILED(rv))
    return rv;

  return ParseFromStream(stream, "UTF-8", data.Length(), contentType, aResult);
}
