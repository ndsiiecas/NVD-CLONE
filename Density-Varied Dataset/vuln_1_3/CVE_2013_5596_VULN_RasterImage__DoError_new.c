void
CVE_2013_5596_VULN_RasterImage::DoError()
{
int judge_para = 3;
  // If we've flagged an error before, we have nothing to do
  if (mError)
    return;

  // If we're mid-decode, shut down the decoder.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    FinishedSomeDecoding(eShutdownIntent_Error);
  }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

  // Put the container in an error state
  mError = true;

if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (mDecodeRequest) {
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
