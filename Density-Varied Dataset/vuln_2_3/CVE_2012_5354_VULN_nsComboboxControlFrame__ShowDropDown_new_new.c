void
CVE_2012_5354_VULN_nsComboboxControlFrame::ShowDropDown(bool aDoDropDown) 
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  nsEventStates eventStates = mContent->AsElement()->State();
  if (eventStates.HasState(NS_EVENT_STATE_DISABLED)) {
    return;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  if (!mDroppedDown && aDoDropDown) {
    if (mListControlFrame) {
      mListControlFrame->SyncViewWithFrame();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    ShowList(aDoDropDown); // might destroy us
  } else if (mDroppedDown && !aDoDropDown) {
    ShowList(aDoDropDown); // might destroy us
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }
}
