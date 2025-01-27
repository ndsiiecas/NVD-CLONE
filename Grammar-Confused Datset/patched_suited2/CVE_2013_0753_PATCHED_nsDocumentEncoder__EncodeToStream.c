NS_IMETHODIMP
CVE_2013_0753_PATCHED_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
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
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    NS_ENSURE_SUCCESS(rv, rv);
  }

  bool chromeCaller = nsContentUtils::IsCallerChrome();
  if (chromeCaller) {
    mStream = aStream;
  }
  nsAutoString buf;

  rv = EncodeToString(buf);

  if (!chromeCaller) {
    mStream = aStream;
  }

  // Force a flush of the last chunk of data.
  FlushText(buf, true);

  mStream = nullptr;
  mUnicodeEncoder = nullptr;

  return rv;
}
