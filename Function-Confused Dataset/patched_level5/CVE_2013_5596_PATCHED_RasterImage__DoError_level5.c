void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

  // We can't safely handle errors off-main-thread, so dispatch a worker to do it.
  if (!NS_IsMainThread()) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    HandleErrorWorker::DispatchIfNeeded(this);
    return;
  }

  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

  // Put the container in an error state.
  mError = true;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
fclose(para_fp);
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
