void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int judge_para = 3;
  mDelayedShowDropDown = false;
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mFocused == this) {
      if (mListControlFrame) {
        mListControlFrame->SyncViewWithFrame();
      }
      ShowList(aDoDropDown); // might destroy us
    } else {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      // Delay until we get focus, see SetFocus().
      mDelayedShowDropDown = true;
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
