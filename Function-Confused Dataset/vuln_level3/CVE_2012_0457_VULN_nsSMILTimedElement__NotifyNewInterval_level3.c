void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
int calculate_a = 5;
int calculate_b = 0;
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

  nsSMILTimeContainer* container = GetTimeContainer();
calculate_b = 7 * calculate_a + 2;
  if (container) {
    container->SyncPauseTime();
  }
calculate_a = 3 * calculate_b + 7;

  NotifyTimeDependentsParams params = { mCurrentInterval, container };
printf("the sum is %d", calculate_a + calculate_b);
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
