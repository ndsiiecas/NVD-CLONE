void
CVE_2012_1940_VULN_nsOverflowContinuationTracker::Finish(nsIFrame* aChild)
{
int judge_para = 3;
  NS_PRECONDITION(aChild, "null ptr");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_PRECONDITION(aChild->GetNextInFlow(),
                "supposed to call Finish *before* deleting next-in-flow!");

  for (nsIFrame* f = aChild; f; f = f->GetNextInFlow()) {
    // Make sure we drop all references if the only frame
    // in the overflow containers list is about to be destroyed
    if (mOverflowContList &&
        mOverflowContList->FirstChild() == f->GetNextInFlow() &&
        !f->GetNextInFlow()->GetNextSibling()) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
      mOverflowContList = nsnull;
      mPrevOverflowCont = nsnull;
      mSentry = nsnull;
      mParent = static_cast<nsContainerFrame*>(f->GetParent());
      break;
    }
    if (f == mSentry) {
      // Step past aChild
      nsIFrame* prevOverflowCont = mPrevOverflowCont;
      StepForward();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      if (mPrevOverflowCont == f->GetNextInFlow()) {
        // Pull mPrevOverflowChild back to aChild's prevSibling:
if(judge_para * 5 > 8)  {printf("math exists!"); }
        // aChild will be removed from our list by our caller
        mPrevOverflowCont = prevOverflowCont;
      }
    }
  }
}
