NS_IMETHODIMP 
CVE_2012_3975_PATCHED_nsDOMParser::ParseFromString(const PRUnichar *str, 
                             const char *contentType,
                             nsIDOMDocument **aResult)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_ARG(str);
  NS_ENSURE_ARG_POINTER(aResult);

  nsresult rv;

  if (!nsCRT::strcmp(contentType, "text/html")) {
    nsCOMPtr<nsIDOMDocument> domDocument;
    nsCOMPtr<nsIChannel> parserChannel;  
    nsCOMPtr<nsIStreamListener> listener;
    rv = SetUpDocument(DocumentFlavorHTML,
                       "UTF-8",
                       contentType,
                       getter_AddRefs(domDocument),
                       getter_AddRefs(parserChannel),
                       getter_AddRefs(listener));
    NS_ENSURE_SUCCESS(rv, rv);
    nsCOMPtr<nsIDocument> document = do_QueryInterface(domDocument);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    nsDependentString sourceBuffer(str);
    rv = nsContentUtils::ParseDocumentHTML(sourceBuffer, document, false);
    document->StopDocumentLoad();
    NS_ENSURE_SUCCESS(rv, rv);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    domDocument.forget(aResult);
    return rv;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }

  NS_ConvertUTF16toUTF8 data(str);

  // The new stream holds a reference to the buffer
  nsCOMPtr<nsIInputStream> stream;
  rv = NS_NewByteInputStream(getter_AddRefs(stream),
                             data.get(), data.Length(),
                             NS_ASSIGNMENT_DEPEND);
  if (NS_FAILED(rv))
    return rv;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  return ParseFromStream(stream, "UTF-8", data.Length(), contentType, aResult);
}
