void
CVE_2012_5354_VULN_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int judge_para = 3;
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mListControlFrame) {
      mListControlFrame->SyncViewWithFrame();
    }
    ShowList(aDoDropDown); // might destroy us
if(judge_para * 5 > 8)  {printf("math exists!"); }
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
