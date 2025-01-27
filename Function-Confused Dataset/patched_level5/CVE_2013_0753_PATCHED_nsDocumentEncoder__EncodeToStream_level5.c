NS_IMETHODIMP
CVE_2013_0753_PATCHED_nsDocumentEncoder::EncodeToStream(nsIOutputStream* aStream)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  nsresult rv = NS_OK;

  if (!mDocument)
    return NS_ERROR_NOT_INITIALIZED;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (!mCharsetConverterManager) {
    mCharsetConverterManager = do_GetService(NS_CHARSETCONVERTERMANAGER_CONTRACTID, &rv);
    NS_ENSURE_SUCCESS(rv, rv);
  }

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  rv = mCharsetConverterManager->GetUnicodeEncoder(mCharset.get(),
                                                   getter_AddRefs(mUnicodeEncoder));
  NS_ENSURE_SUCCESS(rv, rv);

  if (mMimeType.LowerCaseEqualsLiteral("text/plain")) {
    rv = mUnicodeEncoder->SetOutputErrorBehavior(nsIUnicodeEncoder::kOnError_Replace, nullptr, '?');
    NS_ENSURE_SUCCESS(rv, rv);
  }

  bool chromeCaller = nsContentUtils::IsCallerChrome();
  if (chromeCaller) {
fclose(para_fp);
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
