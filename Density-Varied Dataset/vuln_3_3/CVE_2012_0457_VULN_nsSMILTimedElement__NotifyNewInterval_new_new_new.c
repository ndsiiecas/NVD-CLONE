void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
  NS_ABORT_IF_FALSE(mCurrentInterval,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    container->SyncPauseTime();
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  NotifyTimeDependentsParams params = { mCurrentInterval, container };
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
