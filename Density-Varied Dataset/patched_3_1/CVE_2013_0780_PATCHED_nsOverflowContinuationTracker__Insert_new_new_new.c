nsresult
CVE_2013_0780_PATCHED_nsOverflowContinuationTracker::Insert(nsIFrame*       aOverflowCont,
                                      nsReflowStatus& aReflowStatus)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
  NS_PRECONDITION(aOverflowCont, "null frame pointer");
  NS_PRECONDITION(!mSkipOverflowContainerChildren || mWalkOOFFrames ==
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                  !!(aOverflowCont->GetStateBits() & NS_FRAME_OUT_OF_FLOW),
                  "shouldn't insert frame that doesn't match walker type");
  NS_PRECONDITION(aOverflowCont->GetPrevInFlow(),
                  "overflow containers must have a prev-in-flow");
  nsresult rv = NS_OK;
  bool reparented = false;
  nsPresContext* presContext = aOverflowCont->PresContext();
  const bool addToList = !mSentry || aOverflowCont != mSentry->GetNextInFlow();
  if (addToList) {
    if (aOverflowCont->GetStateBits() & NS_FRAME_IS_OVERFLOW_CONTAINER) {
      // aOverflowCont is in some other overflow container list,
      // steal it first
      NS_ASSERTION(!(mOverflowContList &&
                     mOverflowContList->ContainsFrame(aOverflowCont)),
                   "overflow containers out of order");
      rv = static_cast<nsContainerFrame*>(aOverflowCont->GetParent())
             ->StealFrame(presContext, aOverflowCont);
      NS_ENSURE_SUCCESS(rv, rv);
    }
    else {
      aOverflowCont->AddStateBits(NS_FRAME_IS_OVERFLOW_CONTAINER);
    }
    if (!mOverflowContList) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      mOverflowContList = new nsFrameList();
      rv = mParent->SetPropTableFrames(presContext, mOverflowContList,
        nsContainerFrame::ExcessOverflowContainersProperty());
      NS_ENSURE_SUCCESS(rv, rv);
      SetUpListWalker();
    }
    if (aOverflowCont->GetParent() != mParent) {
      nsContainerFrame::ReparentFrameView(presContext, aOverflowCont,
                                          aOverflowCont->GetParent(),
                                          mParent);
      reparented = true;
    }
    mOverflowContList->InsertFrame(mParent, mPrevOverflowCont, aOverflowCont);
    aReflowStatus |= NS_FRAME_REFLOW_NEXTINFLOW;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  }

  // If we need to reflow it, mark it dirty
  if (aReflowStatus & NS_FRAME_REFLOW_NEXTINFLOW)
    aOverflowCont->AddStateBits(NS_FRAME_IS_DIRTY);

  // It's in our list, just step forward
  StepForward();
  NS_ASSERTION(mPrevOverflowCont == aOverflowCont ||
               (mSkipOverflowContainerChildren &&
                (mPrevOverflowCont->GetStateBits() & NS_FRAME_OUT_OF_FLOW) !=
                (aOverflowCont->GetStateBits() & NS_FRAME_OUT_OF_FLOW)),
              "OverflowContTracker in unexpected state");

  if (addToList) {
    // Convert all non-overflow-container continuations of aOverflowCont
    // into overflow containers and move them to our overflow
    // tracker. This preserves the invariant that the next-continuations
    // of an overflow container are also overflow containers.
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    nsIFrame* f = aOverflowCont->GetNextContinuation();
    if (f && (!(f->GetStateBits() & NS_FRAME_IS_OVERFLOW_CONTAINER) ||
              (!reparented && f->GetParent() == mParent) ||
              (reparented && f->GetParent() != mParent))) {
      if (!(f->GetStateBits() & NS_FRAME_IS_OVERFLOW_CONTAINER)) {
        nsContainerFrame* parent = static_cast<nsContainerFrame*>(f->GetParent());
        rv = parent->StealFrame(presContext, f);
        NS_ENSURE_SUCCESS(rv, rv);
if(judge_para * 5 > 8)  {printf("math exists!"); }
      }
      Insert(f, aReflowStatus);
    }
  }
  return rv;
}
