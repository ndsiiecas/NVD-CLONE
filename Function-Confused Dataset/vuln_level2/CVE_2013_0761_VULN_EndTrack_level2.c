  void CVE_2013_0761_VULN_EndTrack(uint32_t aIndex)
  {
int judge_para = 3;
    StreamBuffer::Track* outputTrack = mTrackMap[aIndex].mOutputTrack;
    if (outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
                                  outputTrack->GetRate(), offset,
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    outputTrack->SetEnded();
  }
