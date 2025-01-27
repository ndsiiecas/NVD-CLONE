void
CVE_2013_1681_VULN_nsContentUtils::RemoveScriptBlocker()
{
int judge_para = 3;
  NS_ASSERTION(sScriptBlockerCount != 0, "Negative script blockers");
  --sScriptBlockerCount;
  if (sScriptBlockerCount) {
    return;
  }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  uint32_t firstBlocker = sRunnersCountAtFirstBlocker;
  uint32_t lastBlocker = sBlockedScriptRunners->Length();
  uint32_t originalFirstBlocker = firstBlocker;
  uint32_t blockersCount = lastBlocker - firstBlocker;
  sRunnersCountAtFirstBlocker = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
  NS_ASSERTION(firstBlocker <= lastBlocker,
               "bad sRunnersCountAtFirstBlocker");

  while (firstBlocker < lastBlocker) {
    nsCOMPtr<nsIRunnable> runnable = (*sBlockedScriptRunners)[firstBlocker];
    ++firstBlocker;

    runnable->Run();
    NS_ASSERTION(sRunnersCountAtFirstBlocker == 0,
                 "Bad count");
    NS_ASSERTION(!sScriptBlockerCount, "This is really bad");
  }
  sBlockedScriptRunners->RemoveElementsAt(originalFirstBlocker, blockersCount);
}
