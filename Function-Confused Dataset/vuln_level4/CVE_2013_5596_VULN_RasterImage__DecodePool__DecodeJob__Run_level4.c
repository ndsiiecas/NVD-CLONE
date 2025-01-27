NS_IMETHODIMP
CVE_2013_5596_VULN_RasterImage::DecodePool::DecodeJob::Run()
{
int origin_a, origin_aa[4];
  MutexAutoLock imglock(mImage->mDecodingMutex);

  // If we were interrupted, we shouldn't do any work.
  if (mRequest->mRequestStatus == DecodeRequest::REQUEST_STOPPED) {
    DecodeDoneWorker::NotifyFinishedSomeDecoding(mImage, mRequest);
    return NS_OK;
  }

  // If someone came along and synchronously decoded us, there's nothing for us to do.
  if (!mImage->mDecoder || mImage->IsDecodeFinished()) {
    DecodeDoneWorker::NotifyFinishedSomeDecoding(mImage, mRequest);
    return NS_OK;
  }

  // If we're a decode job that's been enqueued since a previous decode that
  // still needs a new frame, we can't do anything. Wait until the
  // FrameNeededWorker enqueues another frame.
  if (mImage->mDecoder->NeedsNewFrame()) {
    return NS_OK;
  }

  mRequest->mRequestStatus = DecodeRequest::REQUEST_ACTIVE;

  uint32_t oldByteCount = mImage->mBytesDecoded;

  DecodeType type = DECODE_TYPE_UNTIL_DONE_BYTES;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  // Multithreaded decoding can be disabled. If we've done so, we don't want to
  // monopolize the main thread, and will allow a timeout in DecodeSomeOfImage.
  if (NS_IsMainThread()) {
    type = DECODE_TYPE_UNTIL_TIME;
  }

  DecodePool::Singleton()->DecodeSomeOfImage(mImage, type, mRequest->mBytesToDecode);

  uint32_t bytesDecoded = mImage->mBytesDecoded - oldByteCount;

  mRequest->mRequestStatus = DecodeRequest::REQUEST_WORK_DONE;

  // If the decoder needs a new frame, enqueue an event to get it; that event
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  // will enqueue another decode request when it's done.
  if (mImage->mDecoder && mImage->mDecoder->NeedsNewFrame()) {
    FrameNeededWorker::GetNewFrame(mImage);
  }
  // If we aren't yet finished decoding and we have more data in hand, add
  // this request to the back of the list.
  else if (mImage->mDecoder &&
           !mImage->mError &&
           !mImage->IsDecodeFinished() &&
           bytesDecoded < mRequest->mBytesToDecode &&
           bytesDecoded > 0) {
    DecodePool::Singleton()->RequestDecode(mImage);
  } else {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    // Nothing more for us to do - let everyone know what happened.
    DecodeDoneWorker::NotifyFinishedSomeDecoding(mImage, mRequest);
  }

  return NS_OK;
}
