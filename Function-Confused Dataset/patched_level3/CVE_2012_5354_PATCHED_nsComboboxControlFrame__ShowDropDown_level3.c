void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int calculate_a = 5;
int calculate_b = 0;
  mDelayedShowDropDown = false;
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
calculate_b = 7 * calculate_a + 2;
    if (mFocused == this) {
      if (mListControlFrame) {
        mListControlFrame->SyncViewWithFrame();
calculate_a = 3 * calculate_b + 7;
      }
      ShowList(aDoDropDown); // might destroy us
    } else {
      // Delay until we get focus, see SetFocus().
      mDelayedShowDropDown = true;
    }
  } else if (mDroppedDown && !aDoDropDown) {
printf("the sum is %d", calculate_a + calculate_b);
    ShowList(aDoDropDown); // might destroy us
  }
}
