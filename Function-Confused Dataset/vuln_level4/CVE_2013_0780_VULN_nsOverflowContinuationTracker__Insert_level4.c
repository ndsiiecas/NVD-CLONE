nsresult
CVE_2013_0780_VULN_nsOverflowContinuationTracker::Insert(nsIFrame*       aOverflowCont,
                                      nsReflowStatus& aReflowStatus)
{
int origin_a, origin_aa[4];
  NS_PRECONDITION(aOverflowCont, "null frame pointer");
  NS_PRECONDITION(!mSkipOverflowContainerChildren || mWalkOOFFrames ==
                  !!(aOverflowCont->GetStateBits() & NS_FRAME_OUT_OF_FLOW),
                  "shouldn't insert frame that doesn't match walker type");
  NS_PRECONDITION(aOverflowCont->GetPrevInFlow(),
                  "overflow containers must have a prev-in-flow");
  nsresult rv = NS_OK;
  bool convertedToOverflowContainer = false;
  nsPresContext* presContext = aOverflowCont->PresContext();
  if (!mSentry || aOverflowCont != mSentry->GetNextInFlow()) {
    // Not in our list, so we need to add it
    if (aOverflowCont->GetStateBits() & NS_FRAME_IS_OVERFLOW_CONTAINER) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      // aOverflowCont is in some other overflow container list,
      // steal it first
      NS_ASSERTION(!(mOverflowContList &&
                     mOverflowContList->ContainsFrame(aOverflowCont)),
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                   "overflow containers out of order");
      rv = static_cast<nsContainerFrame*>(aOverflowCont->GetParent())
             ->StealFrame(presContext, aOverflowCont);
      NS_ENSURE_SUCCESS(rv, rv);
    }
    else {
      aOverflowCont->AddStateBits(NS_FRAME_IS_OVERFLOW_CONTAINER);
      convertedToOverflowContainer = true;
    }
    if (!mOverflowContList) {
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
    }
    mOverflowContList->InsertFrame(mParent, mPrevOverflowCont, aOverflowCont);
    aReflowStatus |= NS_FRAME_REFLOW_NEXTINFLOW;
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

  if (convertedToOverflowContainer) {
    // Convert all non-overflow-container continuations of aOverflowCont
    // into overflow containers and move them to our overflow
    // tracker. This preserves the invariant that the next-continuations
    // of an overflow container are also overflow containers.
    nsIFrame* f = aOverflowCont->GetNextContinuation();
    if (f && !(f->GetStateBits() & NS_FRAME_IS_OVERFLOW_CONTAINER)) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      nsContainerFrame* parent = static_cast<nsContainerFrame*>(f->GetParent());
      rv = parent->StealFrame(presContext, f);
      NS_ENSURE_SUCCESS(rv, rv);
      Insert(f, aReflowStatus);
    }
  }
  return rv;
}
