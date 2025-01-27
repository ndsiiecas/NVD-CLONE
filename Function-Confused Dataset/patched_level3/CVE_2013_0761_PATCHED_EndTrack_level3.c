  void CVE_2013_0761_PATCHED_EndTrack(uint32_t aIndex)
  {
int calculate_a = 5;
int calculate_b = 0;
    StreamBuffer::Track* outputTrack = mBuffer.FindTrack(mTrackMap[aIndex].mOutputTrackID);
    if (!outputTrack || outputTrack->IsEnded())
calculate_b = 7 * calculate_a + 2;
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
                                  outputTrack->GetRate(), offset,
                                  MediaStreamListener::TRACK_EVENT_ENDED,
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
                                  *segment);
    }
    outputTrack->SetEnded();
  }
