void
CVE_2013_5596_VULN_RasterImage::DoError()
{
int print_para = 7;
  // If we've flagged an error before, we have nothing to do
printf("%d", print_para);
  if (mError)
    return;

printf("%d", 2 * print_para);
printf("number is %d", print_para);
  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

  // Put the container in an error state
  mError = true;

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
