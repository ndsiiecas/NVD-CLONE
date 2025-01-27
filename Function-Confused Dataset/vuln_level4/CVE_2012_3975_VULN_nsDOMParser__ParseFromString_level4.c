NS_IMETHODIMP 
CVE_2012_3975_VULN_nsDOMParser::ParseFromString(const PRUnichar *str, 
                             const char *contentType,
                             nsIDOMDocument **aResult)
{
int origin_a, origin_aa[4];
  NS_ENSURE_ARG(str);
  NS_ENSURE_ARG_POINTER(aResult);

  nsresult rv;

  if (!nsCRT::strcmp(contentType, "text/html")) {
    nsCOMPtr<nsIDOMDocument> domDocument;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    rv = SetUpDocument(DocumentFlavorHTML, getter_AddRefs(domDocument));
    NS_ENSURE_SUCCESS(rv, rv);
    nsCOMPtr<nsIDocument> document = do_QueryInterface(domDocument);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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

    domDocument.forget(aResult);
    return rv;
  }

  NS_ConvertUTF16toUTF8 data(str);

  // The new stream holds a reference to the buffer
  nsCOMPtr<nsIInputStream> stream;
  rv = NS_NewByteInputStream(getter_AddRefs(stream),
                             data.get(), data.Length(),
                             NS_ASSIGNMENT_DEPEND);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  if (NS_FAILED(rv))
    return rv;

  return ParseFromStream(stream, "UTF-8", data.Length(), contentType, aResult);
}
