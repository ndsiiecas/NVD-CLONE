  void CVE_2013_0761_PATCHED_EndTrack(uint32_t aIndex)
  {
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    StreamBuffer::Track* outputTrack = mBuffer.FindTrack(mTrackMap[aIndex].mOutputTrackID);
    if (!outputTrack || outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                  outputTrack->GetRate(), offset,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
    outputTrack->SetEnded();
  }
