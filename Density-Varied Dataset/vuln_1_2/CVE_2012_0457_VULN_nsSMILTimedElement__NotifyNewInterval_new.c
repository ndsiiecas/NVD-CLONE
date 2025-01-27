void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    container->SyncPauseTime();
  }

  NotifyTimeDependentsParams params = { mCurrentInterval, container };
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
