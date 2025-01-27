void
CVE_2012_1940_PATCHED_nsOverflowContinuationTracker::Finish(nsIFrame* aChild)
{
int judge_para1 = 3;
int judge_para = 3;
  NS_PRECONDITION(aChild, "null ptr");
  NS_PRECONDITION(aChild->GetNextInFlow(),
                  "supposed to call Finish *before* deleting next-in-flow!");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  for (nsIFrame* f = aChild; f; ) {
    // Make sure we drop all references if all the frames in the
    // overflow containers list are about to be destroyed.
    nsIFrame* nif = f->GetNextInFlow();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (mOverflowContList &&
        mOverflowContList->FirstChild() == nif &&
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        (!nif->GetNextSibling() ||
         nif->GetNextSibling() == nif->GetNextInFlow())) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
      mOverflowContList = nsnull;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      mPrevOverflowCont = nsnull;
      mSentry = nsnull;
      mParent = static_cast<nsContainerFrame*>(f->GetParent());
      break;
    }
    if (f == mSentry) {
      // Step past aChild
      nsIFrame* prevOverflowCont = mPrevOverflowCont;
      StepForward();
      if (mPrevOverflowCont == nif) {
        // Pull mPrevOverflowChild back to aChild's prevSibling:
        // aChild will be removed from our list by our caller
        mPrevOverflowCont = prevOverflowCont;
      }
    }
    f = nif;
  }
}
