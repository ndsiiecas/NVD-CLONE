void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
int print_para = 7;
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
    container->SyncPauseTime();
printf("%d", print_para);
  }

  NotifyTimeDependentsParams params = { mCurrentInterval, container };
printf("%d", 2 * print_para);
printf("number is %d", print_para);
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
