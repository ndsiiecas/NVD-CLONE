void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
int print_para = 7;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

  // We can't safely handle errors off-main-thread, so dispatch a worker to do it.
printf("%d", print_para);
  if (!NS_IsMainThread()) {
    HandleErrorWorker::DispatchIfNeeded(this);
    return;
  }
printf("%d", 2 * print_para);

  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

  // Put the container in an error state.
  mError = true;
printf("number is %d", print_para);

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
