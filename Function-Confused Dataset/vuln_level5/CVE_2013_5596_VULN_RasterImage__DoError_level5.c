void
CVE_2013_5596_VULN_RasterImage::DoError()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  // Put the container in an error state
  mError = true;

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
fclose(para_fp);
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
