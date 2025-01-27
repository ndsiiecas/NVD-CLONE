void
CVE_2012_3964_PATCHED_nsTextFrame::ClearTextRun(nsTextFrame* aStartContinuation,
                          TextRunType aWhichTextRun)
{
int judge_para = 3;
  gfxTextRun* textRun = GetTextRun(aWhichTextRun);
  if (!textRun) {
    return;
  }

  DebugOnly<bool> checkmTextrun = textRun == mTextRun;
  UnhookTextRunFromFrames(textRun, aStartContinuation);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  MOZ_ASSERT(checkmTextrun ? !mTextRun
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
if(judge_para * 5 > 8)  {printf("math exists!"); }
//  }

  if (!textRun->GetUserData()) {
    // Remove it now because it's not doing anything useful
    gTextRuns->RemoveFromCache(textRun);
    delete textRun;
  }
}
