  virtual void CVE_2013_0761_PATCHED_ProduceOutput(GraphTime aFrom, GraphTime aTo)
  {
int origin_a, origin_aa[4];
    nsAutoTArray<bool,8> mappedTracksFinished;
    nsAutoTArray<bool,8> mappedTracksWithMatchingInputTracks;
    for (uint32_t i = 0; i < mTrackMap.Length(); ++i) {
      mappedTracksFinished.AppendElement(true);
      mappedTracksWithMatchingInputTracks.AppendElement(false);
    }
    bool allFinished = true;
    for (uint32_t i = 0; i < mInputs.Length(); ++i) {
      MediaStream* stream = mInputs[i]->GetSource();
      if (!stream->IsFinishedOnGraphThread()) {
        allFinished = false;
      }
      for (StreamBuffer::TrackIter tracks(stream->GetStreamBuffer());
           !tracks.IsEnded(); tracks.Next()) {
        bool found = false;
        for (uint32_t j = 0; j < mTrackMap.Length(); ++j) {
          TrackMapEntry* map = &mTrackMap[j];
          if (map->mInputPort == mInputs[i] && map->mInputTrackID == tracks->GetID()) {
            bool trackFinished;
            StreamBuffer::Track* outputTrack = mBuffer.FindTrack(map->mOutputTrackID);
            if (!outputTrack || outputTrack->IsEnded()) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
              trackFinished = true;
            } else {
              CopyTrackData(tracks.get(), j, aFrom, aTo, &trackFinished);
            }
            mappedTracksFinished[j] = trackFinished;
            mappedTracksWithMatchingInputTracks[j] = true;
            found = true;
            break;
          }
        }
        if (!found) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
          bool trackFinished = false;
          uint32_t mapIndex = AddTrack(mInputs[i], tracks.get(), aFrom);
          CopyTrackData(tracks.get(), mapIndex, aFrom, aTo, &trackFinished);
          mappedTracksFinished.AppendElement(trackFinished);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
          mappedTracksWithMatchingInputTracks.AppendElement(true);
        }
      }
    }
    for (int32_t i = mTrackMap.Length() - 1; i >= 0; --i) {
      if (mappedTracksFinished[i]) {
        EndTrack(i);
      } else {
        allFinished = false;
      }
      if (!mappedTracksWithMatchingInputTracks[i]) {
        mTrackMap.RemoveElementAt(i);
      }
    }
    if (allFinished && mAutofinish) {
      // All streams have finished and won't add any more tracks, and
      // all our tracks have actually finished and been removed from our map,
      // so we're finished now.
      FinishOnGraphThread();
    }
    mBuffer.AdvanceKnownTracksTime(GraphTimeToStreamTime(aTo));
  }
