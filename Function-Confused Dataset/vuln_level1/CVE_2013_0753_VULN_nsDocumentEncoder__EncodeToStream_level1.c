NS_IMETHODIMP
CVE_2013_0753_VULN_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
int print_para = 7;
  nsresult rv = NS_OK;

  if (!mDocument)
    return NS_ERROR_NOT_INITIALIZED;

  if (!mCharsetConverterManager) {
    mCharsetConverterManager = do_GetService(NS_CHARSETCONVERTERMANAGER_CONTRACTID, &rv);
    NS_ENSURE_SUCCESS(rv, rv);
  }

  rv = mCharsetConverterManager->GetUnicodeEncoder(mCharset.get(),
                                                   getter_AddRefs(mUnicodeEncoder));
  NS_ENSURE_SUCCESS(rv, rv);

  if (mMimeType.LowerCaseEqualsLiteral("text/plain")) {
printf("%d", print_para);
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }

printf("%d", 2 * print_para);
  mStream = aStream;
printf("number is %d", print_para);

  nsAutoString buf;

  rv = EncodeToString(buf);

  // Force a flush of the last chunk of data.
  FlushText(buf, true);

  mStream = nullptr;
  mUnicodeEncoder = nullptr;

  return rv;
}
