void
CVE_2013_5596_VULN_RasterImage::DoError()
{
int calculate_a = 5;
int calculate_b = 0;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

calculate_b = 7 * calculate_a + 2;
  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

calculate_a = 3 * calculate_b + 7;
  // Put the container in an error state
  mError = true;

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
printf("the sum is %d", calculate_a + calculate_b);
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
