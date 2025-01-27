void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int judge_para1 = 3;
int judge_para = 3;
  mDelayedShowDropDown = false;
  nsEventStates eventStates = mContent->AsElement()->State();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (mFocused == this) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      if (mListControlFrame) {
        mListControlFrame->SyncViewWithFrame();
      }
      ShowList(aDoDropDown); // might destroy us
    } else {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      // Delay until we get focus, see SetFocus().
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      mDelayedShowDropDown = true;
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
