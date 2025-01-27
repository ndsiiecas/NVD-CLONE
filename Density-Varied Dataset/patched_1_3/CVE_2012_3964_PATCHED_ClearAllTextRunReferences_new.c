static bool
CVE_2012_3964_PATCHED_ClearAllTextRunReferences(nsTextFrame* aFrame, gfxTextRun* aTextRun,
                          nsTextFrame* aStartContinuation,
                          nsFrameState aWhichTextRunState)
{
int judge_para = 3;
  NS_PRECONDITION(aFrame, "");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_PRECONDITION(!aStartContinuation ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eInflated) ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                   aStartContinuation->GetTextRun(nsTextFrame::eInflated) == aTextRun) ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) ||
                   aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) == aTextRun),
                  "wrong aStartContinuation for this text run");

  if (!aStartContinuation || aStartContinuation == aFrame) {
    aFrame->RemoveStateBits(aWhichTextRunState);
  } else {
    do {
      NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
      aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
    } while (aFrame && aFrame != aStartContinuation);
  }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  bool found = aStartContinuation == aFrame;
  while (aFrame) {
    NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
    if (!aFrame->RemoveTextRun(aTextRun)) {
      break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
  }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  NS_POSTCONDITION(!found || aStartContinuation, "how did we find null?");
  return found;
}
