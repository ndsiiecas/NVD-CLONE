  void CVE_2013_0761_VULN_EndTrack(uint32_t aIndex)
  {
int calculate_a = 5;
int calculate_b = 0;
    StreamBuffer::Track* outputTrack = mTrackMap[aIndex].mOutputTrack;
    if (outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
calculate_b = 7 * calculate_a + 2;
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
                                  outputTrack->GetRate(), offset,
calculate_a = 3 * calculate_b + 7;
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
    }
printf("the sum is %d", calculate_a + calculate_b);
    outputTrack->SetEnded();
  }
