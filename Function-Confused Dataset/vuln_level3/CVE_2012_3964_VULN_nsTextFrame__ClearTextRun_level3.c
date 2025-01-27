void
CVE_2012_3964_VULN_nsTextFrame::ClearTextRun(nsTextFrame* aStartContinuation,
                          TextRunType aWhichTextRun)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  // save textrun because ClearAllTextRunReferences may clear ours
  gfxTextRun* textRun = GetTextRun(aWhichTextRun);

  if (!textRun)
    return;

  UnhookTextRunFromFrames(textRun, aStartContinuation);
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
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    gTextRuns->RemoveFromCache(textRun);
    delete textRun;
  }
}
