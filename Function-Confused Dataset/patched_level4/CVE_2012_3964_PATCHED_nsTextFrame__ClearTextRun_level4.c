void
CVE_2012_3964_PATCHED_nsTextFrame::ClearTextRun(nsTextFrame* aStartContinuation,
                          TextRunType aWhichTextRun)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  gfxTextRun* textRun = GetTextRun(aWhichTextRun);
  if (!textRun) {
    return;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  }

  DebugOnly<bool> checkmTextrun = textRun == mTextRun;
  UnhookTextRunFromFrames(textRun, aStartContinuation);
  MOZ_ASSERT(checkmTextrun ? !mTextRun
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                           : !Properties().Get(UninflatedTextRunProperty()));

  // see comments in BuildTextRunForFrames...
//  if (textRun->GetFlags() & gfxFontGroup::TEXT_IS_PERSISTENT) {
//    NS_ERROR("Shouldn't reach here for now...");
//    // the textrun's text may be referencing a DOM node that has changed,
//    // so we'd better kill this textrun now.
//    if (textRun->GetExpirationState()->IsTracked()) {
//      gTextRuns->RemoveFromCache(textRun);
//    }
//    delete textRun;
//    return;
//  }

  if (!textRun->GetUserData()) {
    // Remove it now because it's not doing anything useful
    gTextRuns->RemoveFromCache(textRun);
    delete textRun;
  }
}
