void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
int calculate_a = 5;
int calculate_b = 0;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

  // We can't safely handle errors off-main-thread, so dispatch a worker to do it.
  if (!NS_IsMainThread()) {
    HandleErrorWorker::DispatchIfNeeded(this);
    return;
  }

calculate_b = 7 * calculate_a + 2;
  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
calculate_a = 3 * calculate_b + 7;
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

  // Put the container in an error state.
  mError = true;

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
printf("the sum is %d", calculate_a + calculate_b);
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
