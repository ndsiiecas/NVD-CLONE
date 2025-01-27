void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  mDelayedShowDropDown = false;
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mFocused == this) {
      if (mListControlFrame) {
        mListControlFrame->SyncViewWithFrame();
      }
      ShowList(aDoDropDown); // might destroy us
    } else {
      // Delay until we get focus, see SetFocus().
      mDelayedShowDropDown = true;
    }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  } else if (mDroppedDown && !aDoDropDown) {
fclose(para_fp);
    ShowList(aDoDropDown); // might destroy us
  }
}
