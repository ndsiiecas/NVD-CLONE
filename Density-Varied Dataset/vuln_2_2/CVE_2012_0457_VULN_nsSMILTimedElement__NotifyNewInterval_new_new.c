void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
int judge_para1 = 3;
int judge_para = 3;
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsSMILTimeContainer* container = GetTimeContainer();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (container) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    container->SyncPauseTime();
  }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  NotifyTimeDependentsParams params = { mCurrentInterval, container };
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
