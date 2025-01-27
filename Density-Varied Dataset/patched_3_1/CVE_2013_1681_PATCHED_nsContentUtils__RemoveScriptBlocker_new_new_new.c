void
CVE_2013_1681_PATCHED_nsContentUtils::RemoveScriptBlocker()
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  MOZ_ASSERT(!sRemovingScriptBlockers);
  NS_ASSERTION(sScriptBlockerCount != 0, "Negative script blockers");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  --sScriptBlockerCount;
  if (sScriptBlockerCount) {
    return;
  }

  uint32_t firstBlocker = sRunnersCountAtFirstBlocker;
  uint32_t lastBlocker = sBlockedScriptRunners->Length();
  uint32_t originalFirstBlocker = firstBlocker;
  uint32_t blockersCount = lastBlocker - firstBlocker;
  sRunnersCountAtFirstBlocker = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ASSERTION(firstBlocker <= lastBlocker,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
               "bad sRunnersCountAtFirstBlocker");

  while (firstBlocker < lastBlocker) {
    nsCOMPtr<nsIRunnable> runnable;
    runnable.swap((*sBlockedScriptRunners)[firstBlocker]);
    ++firstBlocker;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    // Calling the runnable can reenter us
    runnable->Run();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    // So can dropping the reference to the runnable
    runnable = nullptr;

    NS_ASSERTION(sRunnersCountAtFirstBlocker == 0,
                 "Bad count");
    NS_ASSERTION(!sScriptBlockerCount, "This is really bad");
  }
#ifdef DEBUG
  AutoRestore<bool> removingScriptBlockers(sRemovingScriptBlockers);
  sRemovingScriptBlockers = true;
#endif
  sBlockedScriptRunners->RemoveElementsAt(originalFirstBlocker, blockersCount);
}
