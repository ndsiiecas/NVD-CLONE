  void CVE_2013_0761_PATCHED_EndTrack(uint32_t aIndex)
  {
int origin_a, origin_aa[4];
    StreamBuffer::Track* outputTrack = mBuffer.FindTrack(mTrackMap[aIndex].mOutputTrackID);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (!outputTrack || outputTrack->IsEnded())
      return;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
                                  outputTrack->GetRate(), offset,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
    }
    outputTrack->SetEnded();
  }
