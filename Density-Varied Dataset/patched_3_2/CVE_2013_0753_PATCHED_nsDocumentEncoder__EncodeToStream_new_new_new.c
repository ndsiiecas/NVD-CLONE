NS_IMETHODIMP
CVE_2013_0753_PATCHED_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
  nsresult rv = NS_OK;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  bool chromeCaller = nsContentUtils::IsCallerChrome();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  if (chromeCaller) {
    mStream = aStream;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  }
  nsAutoString buf;

  rv = EncodeToString(buf);

  if (!chromeCaller) {
    mStream = aStream;
  }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // Force a flush of the last chunk of data.
  FlushText(buf, true);

  mStream = nullptr;
  mUnicodeEncoder = nullptr;

  return rv;
}
