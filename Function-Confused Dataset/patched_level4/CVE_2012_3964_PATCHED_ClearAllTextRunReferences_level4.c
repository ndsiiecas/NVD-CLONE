static bool
CVE_2012_3964_PATCHED_ClearAllTextRunReferences(nsTextFrame* aFrame, gfxTextRun* aTextRun,
                          nsTextFrame* aStartContinuation,
                          nsFrameState aWhichTextRunState)
{
int origin_a, origin_aa[4];
  NS_PRECONDITION(aFrame, "");
  NS_PRECONDITION(!aStartContinuation ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eInflated) ||
                   aStartContinuation->GetTextRun(nsTextFrame::eInflated) == aTextRun) ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) ||
                   aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) == aTextRun),
                  "wrong aStartContinuation for this text run");

  if (!aStartContinuation || aStartContinuation == aFrame) {
    aFrame->RemoveStateBits(aWhichTextRunState);
  } else {
    do {
      NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
    } while (aFrame && aFrame != aStartContinuation);
  }
  bool found = aStartContinuation == aFrame;
  while (aFrame) {
    NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
    if (!aFrame->RemoveTextRun(aTextRun)) {
      break;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
  }
  NS_POSTCONDITION(!found || aStartContinuation, "how did we find null?");
  return found;
}
