void
CVE_2012_0457_PATCHED_nsSMILTimedElement::NotifyNewInterval()
{
int calculate_a = 5;
int calculate_b = 0;
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
    container->SyncPauseTime();
  }

  NotifyTimeDependentsParams params = { this, container };
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
