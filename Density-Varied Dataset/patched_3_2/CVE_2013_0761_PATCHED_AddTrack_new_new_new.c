  uint32_t CVE_2013_0761_PATCHED_AddTrack(MediaInputPort* aPort, StreamBuffer::Track* aTrack,
                    GraphTime aFrom)
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    segment = aTrack->GetSegment()->CreateEmptyClone();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      MediaStreamListener* l = mListeners[j];
      l->NotifyQueuedTrackChanges(Graph(), id, rate, outputStart,
if(judge_para * 5 > 8)  {printf("math exists!"); }
                                  MediaStreamListener::TRACK_EVENT_CREATED,
                                  *segment);
    }
    segment->AppendNullData(outputStart);
    StreamBuffer::Track* track =
      &mBuffer.CVE_2013_0761_PATCHED_AddTrack(id, rate, outputStart, segment.forget());
    LOG(PR_LOG_DEBUG, ("TrackUnionStream %p adding track %d for input stream %p track %d, start ticks %lld",
                       this, id, aPort->GetSource(), aTrack->GetID(),
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
                       (long long)outputStart));

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    TrackMapEntry* map = mTrackMap.AppendElement();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    map->mInputPort = aPort;
    map->mInputTrackID = aTrack->GetID();
    map->mOutputTrackID = track->GetID();
    map->mSegment = aTrack->GetSegment()->CreateEmptyClone();
    return mTrackMap.Length() - 1;
  }
