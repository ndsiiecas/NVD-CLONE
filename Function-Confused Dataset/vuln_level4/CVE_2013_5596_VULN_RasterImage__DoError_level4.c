void
CVE_2013_5596_VULN_RasterImage::DoError()
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

  // Put the container in an error state
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
