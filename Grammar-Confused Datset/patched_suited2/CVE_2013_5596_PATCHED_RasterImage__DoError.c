void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  // We can't safely handle errors off-main-thread, so dispatch a worker to do it.
  if (!NS_IsMainThread()) {
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

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
