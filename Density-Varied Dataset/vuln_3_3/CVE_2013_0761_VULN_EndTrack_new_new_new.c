  void CVE_2013_0761_VULN_EndTrack(uint32_t aIndex)
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    StreamBuffer::Track* outputTrack = mTrackMap[aIndex].mOutputTrack;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                  outputTrack->GetRate(), offset,
                                  MediaStreamListener::TRACK_EVENT_ENDED,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                  *segment);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    outputTrack->SetEnded();
  }
