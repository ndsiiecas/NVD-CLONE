void
CVE_2013_1681_VULN_nsContentUtils::RemoveScriptBlocker()
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ASSERTION(sScriptBlockerCount != 0, "Negative script blockers");
  --sScriptBlockerCount;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  if (sScriptBlockerCount) {
    return;
  }

  uint32_t firstBlocker = sRunnersCountAtFirstBlocker;
  uint32_t lastBlocker = sBlockedScriptRunners->Length();
  uint32_t originalFirstBlocker = firstBlocker;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  uint32_t blockersCount = lastBlocker - firstBlocker;
  sRunnersCountAtFirstBlocker = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  NS_ASSERTION(firstBlocker <= lastBlocker,
               "bad sRunnersCountAtFirstBlocker");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  while (firstBlocker < lastBlocker) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    nsCOMPtr<nsIRunnable> runnable = (*sBlockedScriptRunners)[firstBlocker];
    ++firstBlocker;

    runnable->Run();
    NS_ASSERTION(sRunnersCountAtFirstBlocker == 0,
                 "Bad count");
    NS_ASSERTION(!sScriptBlockerCount, "This is really bad");
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }
  sBlockedScriptRunners->RemoveElementsAt(originalFirstBlocker, blockersCount);
}
