void
CVE_2012_5354_VULN_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int calculate_a = 5;
int calculate_b = 0;
  nsEventStates eventStates = mContent->AsElement()->State();
calculate_b = 7 * calculate_a + 2;
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
  }
calculate_a = 3 * calculate_b + 7;

  if (!mDroppedDown && aDoDropDown) {
    if (mListControlFrame) {
      mListControlFrame->SyncViewWithFrame();
printf("the sum is %d", calculate_a + calculate_b);
    }
    ShowList(aDoDropDown); // might destroy us
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
  }
}
