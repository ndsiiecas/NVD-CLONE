static bool
CVE_2012_3964_PATCHED_ClearAllTextRunReferences(nsTextFrame* aFrame, gfxTextRun* aTextRun,
                          nsTextFrame* aStartContinuation,
                          nsFrameState aWhichTextRunState)
{
int calculate_a = 5;
int calculate_b = 0;
  NS_PRECONDITION(aFrame, "");
  NS_PRECONDITION(!aStartContinuation ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eInflated) ||
calculate_b = 7 * calculate_a + 2;
                   aStartContinuation->GetTextRun(nsTextFrame::eInflated) == aTextRun) ||
                  (!aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) ||
                   aStartContinuation->GetTextRun(nsTextFrame::eNotInflated) == aTextRun),
                  "wrong aStartContinuation for this text run");

  if (!aStartContinuation || aStartContinuation == aFrame) {
    aFrame->RemoveStateBits(aWhichTextRunState);
  } else {
calculate_a = 3 * calculate_b + 7;
    do {
      NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
      aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
    } while (aFrame && aFrame != aStartContinuation);
printf("the sum is %d", calculate_a + calculate_b);
  }
  bool found = aStartContinuation == aFrame;
  while (aFrame) {
    NS_ASSERTION(aFrame->GetType() == nsGkAtoms::textFrame, "Bad frame");
    if (!aFrame->RemoveTextRun(aTextRun)) {
      break;
    }
    aFrame = static_cast<nsTextFrame*>(aFrame->GetNextContinuation());
  }
  NS_POSTCONDITION(!found || aStartContinuation, "how did we find null?");
  return found;
}
