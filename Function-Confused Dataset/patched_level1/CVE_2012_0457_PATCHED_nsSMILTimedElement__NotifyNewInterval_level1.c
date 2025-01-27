void
CVE_2012_0457_PATCHED_nsSMILTimedElement::NotifyNewInterval()
{
int print_para = 7;
  NS_ABORT_IF_FALSE(mCurrentInterval,
printf("%d", print_para);
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
printf("%d", 2 * print_para);
    container->SyncPauseTime();
  }
printf("number is %d", print_para);

  NotifyTimeDependentsParams params = { this, container };
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
