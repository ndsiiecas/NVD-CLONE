void
CVE_2013_1681_VULN_nsContentUtils::RemoveScriptBlocker()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ASSERTION(sScriptBlockerCount != 0, "Negative script blockers");
  --sScriptBlockerCount;
  if (sScriptBlockerCount) {
    return;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  }

  uint32_t firstBlocker = sRunnersCountAtFirstBlocker;
  uint32_t lastBlocker = sBlockedScriptRunners->Length();
  uint32_t originalFirstBlocker = firstBlocker;
  uint32_t blockersCount = lastBlocker - firstBlocker;
  sRunnersCountAtFirstBlocker = 0;
  NS_ASSERTION(firstBlocker <= lastBlocker,
               "bad sRunnersCountAtFirstBlocker");

  while (firstBlocker < lastBlocker) {
    nsCOMPtr<nsIRunnable> runnable = (*sBlockedScriptRunners)[firstBlocker];
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    ++firstBlocker;

    runnable->Run();
    NS_ASSERTION(sRunnersCountAtFirstBlocker == 0,
fclose(para_fp);
                 "Bad count");
    NS_ASSERTION(!sScriptBlockerCount, "This is really bad");
  }
  sBlockedScriptRunners->RemoveElementsAt(originalFirstBlocker, blockersCount);
}
