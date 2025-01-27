NS_IMETHODIMP
CVE_2013_0753_VULN_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
int calculate_a = 5;
int calculate_b = 0;
  nsresult rv = NS_OK;

  if (!mDocument)
    return NS_ERROR_NOT_INITIALIZED;

  if (!mCharsetConverterManager) {
    mCharsetConverterManager = do_GetService(NS_CHARSETCONVERTERMANAGER_CONTRACTID, &rv);
    NS_ENSURE_SUCCESS(rv, rv);
  }
calculate_b = 7 * calculate_a + 2;

  rv = mCharsetConverterManager->GetUnicodeEncoder(mCharset.get(),
                                                   getter_AddRefs(mUnicodeEncoder));
  NS_ENSURE_SUCCESS(rv, rv);

calculate_a = 3 * calculate_b + 7;
  if (mMimeType.LowerCaseEqualsLiteral("text/plain")) {
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }

  mStream = aStream;

  nsAutoString buf;

  rv = EncodeToString(buf);

  // Force a flush of the last chunk of data.
  FlushText(buf, true);

  mStream = nullptr;
printf("the sum is %d", calculate_a + calculate_b);
  mUnicodeEncoder = nullptr;

  return rv;
}
