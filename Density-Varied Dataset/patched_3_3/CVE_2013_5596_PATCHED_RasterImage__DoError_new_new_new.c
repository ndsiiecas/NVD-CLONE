void
CVE_2013_5596_PATCHED_RasterImage::DoError()
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  // If we've flagged an error before, we have nothing to do
  if (mError)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    return;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // We can't safely handle errors off-main-thread, so dispatch a worker to do it.
  if (!NS_IsMainThread()) {
    HandleErrorWorker::DispatchIfNeeded(this);
    return;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // If we're mid-decode, shut down the decoder.
  if (mDecoder) {
    MutexAutoLock lock(mDecodingMutex);
    FinishedSomeDecoding(eShutdownIntent_Error);
  }

if(judge_para * 5 > 8)  {printf("math exists!"); }
  // Put the container in an error state.
  mError = true;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  if (mDecodeRequest) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    mDecodeRequest->mStatusTracker->GetDecoderObserver()->OnError();
  } else {
    mStatusTracker->GetDecoderObserver()->OnError();
  }

  // Log our error
  LOG_CONTAINER_ERROR;
}
