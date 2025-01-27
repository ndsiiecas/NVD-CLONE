void
CVE_2012_3964_PATCHED_nsTextFrame::ClearTextRun(nsTextFrame* aStartContinuation,
                          TextRunType aWhichTextRun)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  gfxTextRun* textRun = GetTextRun(aWhichTextRun);
  if (!textRun) {
    return;
  }

  DebugOnly<bool> checkmTextrun = textRun == mTextRun;
  UnhookTextRunFromFrames(textRun, aStartContinuation);
  MOZ_ASSERT(checkmTextrun ? !mTextRun
                           : !Properties().Get(UninflatedTextRunProperty()));

  // see comments in BuildTextRunForFrames...
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
//  if (textRun->GetFlags() & gfxFontGroup::TEXT_IS_PERSISTENT) {
//    NS_ERROR("Shouldn't reach here for now...");
//    // the textrun's text may be referencing a DOM node that has changed,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
//    // so we'd better kill this textrun now.
//    if (textRun->GetExpirationState()->IsTracked()) {
//      gTextRuns->RemoveFromCache(textRun);
//    }
//    delete textRun;
//    return;
fclose(para_fp);
//  }

  if (!textRun->GetUserData()) {
    // Remove it now because it's not doing anything useful
    gTextRuns->RemoveFromCache(textRun);
    delete textRun;
  }
}
