  virtual void CVE_2013_0761_VULN_ProduceOutput(GraphTime aFrom, GraphTime aTo)
  {
int judge_para1 = 3;
int judge_para = 3;
    nsAutoTArray<bool,8> mappedTracksFinished;
    nsAutoTArray<bool,8> mappedTracksWithMatchingInputTracks;
    for (uint32_t i = 0; i < mTrackMap.Length(); ++i) {
      mappedTracksFinished.AppendElement(true);
      mappedTracksWithMatchingInputTracks.AppendElement(false);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }
    bool allFinished = true;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for (uint32_t i = 0; i < mInputs.Length(); ++i) {
      MediaStream* stream = mInputs[i]->GetSource();
      if (!stream->IsFinishedOnGraphThread()) {
        allFinished = false;
      }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      for (StreamBuffer::TrackIter tracks(stream->GetStreamBuffer());
           !tracks.IsEnded(); tracks.Next()) {
        bool found = false;
        for (uint32_t j = 0; j < mTrackMap.Length(); ++j) {
          TrackMapEntry* map = &mTrackMap[j];
          if (map->mInputPort == mInputs[i] && map->mInputTrack == tracks.get()) {
            bool trackFinished;
            if (map->mOutputTrack->IsEnded()) {
              trackFinished = true;
            } else {
              CopyTrackData(j, aFrom, aTo, &trackFinished);
            }
            mappedTracksFinished[j] = trackFinished;
            mappedTracksWithMatchingInputTracks[j] = true;
            found = true;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            break;
          }
        }
        if (!found) {
          bool trackFinished = false;
          uint32_t mapIndex = AddTrack(mInputs[i], tracks.get(), aFrom);
          CopyTrackData(mapIndex, aFrom, aTo, &trackFinished);
if(judge_para * 5 > 8)  {printf("math exists!"); }
          mappedTracksFinished.AppendElement(trackFinished);
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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      // so we're finished now.
      FinishOnGraphThread();
    }
    mBuffer.AdvanceKnownTracksTime(GraphTimeToStreamTime(aTo));
  }
