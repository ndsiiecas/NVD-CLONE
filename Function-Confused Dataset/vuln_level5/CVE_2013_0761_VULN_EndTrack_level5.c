  void CVE_2013_0761_VULN_EndTrack(uint32_t aIndex)
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    StreamBuffer::Track* outputTrack = mTrackMap[aIndex].mOutputTrack;
    if (outputTrack->IsEnded())
      return;
    for (uint32_t j = 0; j < mListeners.Length(); ++j) {
      MediaStreamListener* l = mListeners[j];
      TrackTicks offset = outputTrack->GetSegment()->GetDuration();
      nsAutoPtr<MediaSegment> segment;
      segment = outputTrack->GetSegment()->CreateEmptyClone();
      l->NotifyQueuedTrackChanges(Graph(), outputTrack->GetID(),
                                  outputTrack->GetRate(), offset,
                                  MediaStreamListener::TRACK_EVENT_ENDED,
                                  *segment);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    }
fclose(para_fp);
    outputTrack->SetEnded();
  }
