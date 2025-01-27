void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
  mDelayedShowDropDown = false;
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mFocused == this) {
      if (mListControlFrame) {
        mListControlFrame->SyncViewWithFrame();
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
      }
      ShowList(aDoDropDown); // might destroy us
    } else {
      // Delay until we get focus, see SetFocus().
      mDelayedShowDropDown = true;
    }
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
