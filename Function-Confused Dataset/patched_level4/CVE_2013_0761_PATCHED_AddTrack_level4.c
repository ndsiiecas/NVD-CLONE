  uint32_t CVE_2013_0761_PATCHED_AddTrack(MediaInputPort* aPort, StreamBuffer::Track* aTrack,
                    GraphTime aFrom)
  {
int origin_a, origin_aa[4];
    // Use the ID of the source track if we can, otherwise allocate a new
    // unique ID
    TrackID id = NS_MAX(mMaxTrackID + 1, aTrack->GetID());
    mMaxTrackID = id;

    TrackRate rate = aTrack->GetRate();
    // Round up the track start time so the track, if anything, starts a
    // little later than the true time. This means we'll have enough
    // samples in our input stream to go just beyond the destination time.
    TrackTicks outputStart = TimeToTicksRoundUp(rate, GraphTimeToStreamTime(aFrom));

    nsAutoPtr<MediaSegment> segment;
    segment = aTrack->GetSegment()->CreateEmptyClone();
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      l->NotifyQueuedTrackChanges(Graph(), id, rate, outputStart,
                                  MediaStreamListener::TRACK_EVENT_CREATED,
                                  *segment);
    }
    segment->AppendNullData(outputStart);
    StreamBuffer::Track* track =
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      &mBuffer.CVE_2013_0761_PATCHED_AddTrack(id, rate, outputStart, segment.forget());
    LOG(PR_LOG_DEBUG, ("TrackUnionStream %p adding track %d for input stream %p track %d, start ticks %lld",
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                       this, id, aPort->GetSource(), aTrack->GetID(),
                       (long long)outputStart));

    TrackMapEntry* map = mTrackMap.AppendElement();
    map->mInputPort = aPort;
    map->mInputTrackID = aTrack->GetID();
    map->mOutputTrackID = track->GetID();
    map->mSegment = aTrack->GetSegment()->CreateEmptyClone();
    return mTrackMap.Length() - 1;
  }
