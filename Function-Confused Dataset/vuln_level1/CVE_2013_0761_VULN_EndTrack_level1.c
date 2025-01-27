  void CVE_2013_0761_VULN_EndTrack(uint32_t aIndex)
  {
int print_para = 7;
printf("%d", print_para);
    StreamBuffer::Track* outputTrack = mTrackMap[aIndex].mOutputTrack;
    if (outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
printf("%d", 2 * print_para);
                                  outputTrack->GetRate(), offset,
printf("number is %d", print_para);
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
    }
    outputTrack->SetEnded();
  }
