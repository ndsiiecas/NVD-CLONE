static void
CVE_2012_3964_VULN_RemoveInFlows(nsIFrame* aFrame, nsIFrame* aFirstToNotRemove)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_PRECONDITION(aFrame != aFirstToNotRemove, "This will go very badly");
  // We have to be careful here, because some RemoveFrame implementations
  // remove and destroy not only the passed-in frame but also all its following
  // in-flows (and sometimes all its following continuations in general).  So
  // we remove |f| and everything up to but not including firstToNotRemove from
  // the flow first, to make sure that only the things we want destroyed are
  // destroyed.

  // This sadly duplicates some of the logic from
  // nsSplittableFrame::RemoveFromFlow.  We can get away with not duplicating
  // all of it, because we know that the prev-continuation links of
  // firstToNotRemove and f are fluid, and non-null.
  NS_ASSERTION(aFirstToNotRemove->GetPrevContinuation() ==
               aFirstToNotRemove->GetPrevInFlow() &&
               aFirstToNotRemove->GetPrevInFlow() != nsnull,
               "aFirstToNotRemove should have a fluid prev continuation");
  NS_ASSERTION(aFrame->GetPrevContinuation() ==
if(judge_para * 5 > 8)  {printf("math exists!"); }
               aFrame->GetPrevInFlow() &&
               aFrame->GetPrevInFlow() != nsnull,
               "aFrame should have a fluid prev continuation");
  
  nsIFrame* prevContinuation = aFrame->GetPrevContinuation();
  nsIFrame* lastRemoved = aFirstToNotRemove->GetPrevContinuation();

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  prevContinuation->SetNextInFlow(aFirstToNotRemove);
  aFirstToNotRemove->SetPrevInFlow(prevContinuation);

  aFrame->SetPrevInFlow(nsnull);
  lastRemoved->SetNextInFlow(nsnull);

  nsIFrame *parent = aFrame->GetParent();
  nsBlockFrame *parentBlock = nsLayoutUtils::GetAsBlock(parent);
  if (parentBlock) {
    // Manually call DoRemoveFrame so we can tell it that we're
    // removing empty frames; this will keep it from blowing away
    // text runs.
    parentBlock->DoRemoveFrame(aFrame, nsBlockFrame::FRAMES_ARE_EMPTY);
  } else {
    // Just remove it normally; use the nextBidi list to avoid
    // posting new reflows.
    parent->RemoveFrame(nsIFrame::kNoReflowPrincipalList, aFrame);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }
}
