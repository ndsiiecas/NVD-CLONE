void
CVE_2012_5354_VULN_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }

  if (!mDroppedDown && aDoDropDown) {
    if (mListControlFrame) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
      mListControlFrame->SyncViewWithFrame();
    }
    ShowList(aDoDropDown); // might destroy us
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
