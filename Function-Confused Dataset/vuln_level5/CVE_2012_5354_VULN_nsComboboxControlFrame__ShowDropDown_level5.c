void
CVE_2012_5354_VULN_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mListControlFrame) {
      mListControlFrame->SyncViewWithFrame();
    }
    ShowList(aDoDropDown); // might destroy us
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
