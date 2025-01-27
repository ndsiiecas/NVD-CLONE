void
CVE_2012_0457_VULN_nsSMILTimedElement::NotifyNewInterval()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ABORT_IF_FALSE(mCurrentInterval,
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
      "Attempting to notify dependents of a new interval but the interval "
      "is not set");

  nsSMILTimeContainer* container = GetTimeContainer();
  if (container) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    container->SyncPauseTime();
fclose(para_fp);
  }

  NotifyTimeDependentsParams params = { mCurrentInterval, container };
  mTimeDependents.EnumerateEntries(NotifyNewIntervalCallback, &params);
}
