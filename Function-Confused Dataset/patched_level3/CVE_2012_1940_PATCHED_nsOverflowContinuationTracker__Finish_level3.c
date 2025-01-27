void
CVE_2012_1940_PATCHED_nsOverflowContinuationTracker::Finish(nsIFrame* aChild)
{
int calculate_a = 5;
int calculate_b = 0;
  NS_PRECONDITION(aChild, "null ptr");
  NS_PRECONDITION(aChild->GetNextInFlow(),
                  "supposed to call Finish *before* deleting next-in-flow!");

  for (nsIFrame* f = aChild; f; ) {
    // Make sure we drop all references if all the frames in the
    // overflow containers list are about to be destroyed.
    nsIFrame* nif = f->GetNextInFlow();
calculate_b = 7 * calculate_a + 2;
    if (mOverflowContList &&
        mOverflowContList->FirstChild() == nif &&
        (!nif->GetNextSibling() ||
         nif->GetNextSibling() == nif->GetNextInFlow())) {
      mOverflowContList = nsnull;
      mPrevOverflowCont = nsnull;
      mSentry = nsnull;
      mParent = static_cast<nsContainerFrame*>(f->GetParent());
      break;
calculate_a = 3 * calculate_b + 7;
    }
    if (f == mSentry) {
      // Step past aChild
      nsIFrame* prevOverflowCont = mPrevOverflowCont;
      StepForward();
      if (mPrevOverflowCont == nif) {
        // Pull mPrevOverflowChild back to aChild's prevSibling:
printf("the sum is %d", calculate_a + calculate_b);
        // aChild will be removed from our list by our caller
        mPrevOverflowCont = prevOverflowCont;
      }
    }
    f = nif;
  }
}
