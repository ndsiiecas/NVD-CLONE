NS_IMETHODIMP
CVE_2013_0753_VULN_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  nsresult rv = NS_OK;

  if (!mDocument)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_ERROR_NOT_INITIALIZED;

  if (!mCharsetConverterManager) {
    mCharsetConverterManager = do_GetService(NS_CHARSETCONVERTERMANAGER_CONTRACTID, &rv);
    NS_ENSURE_SUCCESS(rv, rv);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  }

  rv = mCharsetConverterManager->GetUnicodeEncoder(mCharset.get(),
                                                   getter_AddRefs(mUnicodeEncoder));
  NS_ENSURE_SUCCESS(rv, rv);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  if (mMimeType.LowerCaseEqualsLiteral("text/plain")) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }

  mStream = aStream;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  nsAutoString buf;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  rv = EncodeToString(buf);

  // Force a flush of the last chunk of data.
  FlushText(buf, true);

  mStream = nullptr;
  mUnicodeEncoder = nullptr;

  return rv;
}
