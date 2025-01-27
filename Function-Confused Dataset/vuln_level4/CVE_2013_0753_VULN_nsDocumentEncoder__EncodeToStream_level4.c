NS_IMETHODIMP
CVE_2013_0753_VULN_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
int origin_a, origin_aa[4];
  nsresult rv = NS_OK;

  if (!mDocument)
    return NS_ERROR_NOT_INITIALIZED;

  if (!mCharsetConverterManager) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    mCharsetConverterManager = do_GetService(NS_CHARSETCONVERTERMANAGER_CONTRACTID, &rv);
    NS_ENSURE_SUCCESS(rv, rv);
  }

  rv = mCharsetConverterManager->GetUnicodeEncoder(mCharset.get(),
                                                   getter_AddRefs(mUnicodeEncoder));
  NS_ENSURE_SUCCESS(rv, rv);

  if (mMimeType.LowerCaseEqualsLiteral("text/plain")) {
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  mStream = aStream;

  nsAutoString buf;

  rv = EncodeToString(buf);

  // Force a flush of the last chunk of data.
  FlushText(buf, true);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  mStream = nullptr;
  mUnicodeEncoder = nullptr;

  return rv;
}
