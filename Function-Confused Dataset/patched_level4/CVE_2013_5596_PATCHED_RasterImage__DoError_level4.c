void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
int origin_a, origin_aa[4];
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  // Put the container in an error state.
  mError = true;

  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  // Log our error
  LOG_CONTAINER_ERROR;
}
