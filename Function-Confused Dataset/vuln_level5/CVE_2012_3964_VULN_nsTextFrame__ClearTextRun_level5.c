void
CVE_2012_3964_VULN_nsTextFrame::ClearTextRun(nsTextFrame* aStartContinuation,
                          TextRunType aWhichTextRun)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
//    if (textRun->GetExpirationState()->IsTracked()) {
//      gTextRuns->RemoveFromCache(textRun);
//    }
//    delete textRun;
//    return;
//  }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  if (!textRun->GetUserData()) {
    // Remove it now because it's not doing anything useful
    gTextRuns->RemoveFromCache(textRun);
    delete textRun;
fclose(para_fp);
  }
}
