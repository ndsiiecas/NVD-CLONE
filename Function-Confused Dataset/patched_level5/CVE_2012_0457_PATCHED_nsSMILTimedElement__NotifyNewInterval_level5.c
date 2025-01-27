void
CVE_2012_0457_PATCHED_nsSMILTimedElement::NotifyNewInterval()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  NS_ABORT_IF_FALSE(mCurrentInterval,
      "Attempting to notify dependents of a new interval but the interval "
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
      "is not set");
fclose(para_fp);

  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
    container->SyncPauseTime();
  }

  NotifyTimeDependentsParams params = { this, container };
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
