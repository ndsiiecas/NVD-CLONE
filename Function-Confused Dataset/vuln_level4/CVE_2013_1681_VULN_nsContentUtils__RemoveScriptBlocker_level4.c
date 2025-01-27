void
CVE_2013_1681_VULN_nsContentUtils::RemoveScriptBlocker()
{
int origin_a, origin_aa[4];
  NS_ASSERTION(sScriptBlockerCount != 0, "Negative script blockers");
  --sScriptBlockerCount;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  if (sScriptBlockerCount) {
    return;
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
    ++firstBlocker;

    runnable->Run();
    NS_ASSERTION(sRunnersCountAtFirstBlocker == 0,
                 "Bad count");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    NS_ASSERTION(!sScriptBlockerCount, "This is really bad");
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }
  sBlockedScriptRunners->RemoveElementsAt(originalFirstBlocker, blockersCount);
}
