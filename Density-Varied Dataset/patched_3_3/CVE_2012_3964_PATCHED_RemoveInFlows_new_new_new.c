static void
CVE_2012_3964_PATCHED_RemoveInFlows(nsTextFrame* aFrame, nsTextFrame* aFirstToNotRemove)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_PRECONDITION(aFrame != aFirstToNotRemove, "This will go very badly");
  // We have to be careful here, because some RemoveFrame implementations
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  // remove and destroy not only the passed-in frame but also all its following
  // in-flows (and sometimes all its following continuations in general).  So
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // we remove |f| and everything up to but not including firstToNotRemove from
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // the flow first, to make sure that only the things we want destroyed are
  // destroyed.

  // This sadly duplicates some of the logic from
  // nsSplittableFrame::RemoveFromFlow.  We can get away with not duplicating
  // all of it, because we know that the prev-continuation links of
  // firstToNotRemove and f are fluid, and non-null.
  NS_ASSERTION(aFirstToNotRemove->GetPrevContinuation() ==
               aFirstToNotRemove->GetPrevInFlow() &&
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
               aFirstToNotRemove->GetPrevInFlow() != nsnull,
               "aFirstToNotRemove should have a fluid prev continuation");
  NS_ASSERTION(aFrame->GetPrevContinuation() ==
               aFrame->GetPrevInFlow() &&
               aFrame->GetPrevInFlow() != nsnull,
               "aFrame should have a fluid prev continuation");
  
  nsIFrame* prevContinuation = aFrame->GetPrevContinuation();
  nsIFrame* lastRemoved = aFirstToNotRemove->GetPrevContinuation();
  nsIFrame* parent = aFrame->GetParent();
  nsBlockFrame* parentBlock = nsLayoutUtils::GetAsBlock(parent);
  if (!parentBlock) {
    // Clear the text run on the first frame we'll remove to make sure none of
    // the frames we keep shares its text run.  We need to do this now, before
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    // we unlink the frames to remove from the flow, because DestroyFrom calls
    // ClearTextRuns() and that will start at the first frame with the text
    // run and walk the continuations.  We only need to care about the first
    // and last frames we remove since text runs are contiguous.
    aFrame->ClearTextRuns();
    if (aFrame != lastRemoved) {
      // Clear the text run on the last frame we'll remove for the same reason.
      static_cast<nsTextFrame*>(lastRemoved)->ClearTextRuns();
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }

  prevContinuation->SetNextInFlow(aFirstToNotRemove);
  aFirstToNotRemove->SetPrevInFlow(prevContinuation);

  aFrame->SetPrevInFlow(nsnull);
  lastRemoved->SetNextInFlow(nsnull);

  if (parentBlock) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    // Manually call DoRemoveFrame so we can tell it that we're
    // removing empty frames; this will keep it from blowing away
    // text runs.
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    parentBlock->DoRemoveFrame(aFrame, nsBlockFrame::FRAMES_ARE_EMPTY);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  } else {
    // Just remove it normally; use kNoReflowPrincipalList to avoid posting
    // new reflows.
    parent->RemoveFrame(nsIFrame::kNoReflowPrincipalList, aFrame);
  }
}
