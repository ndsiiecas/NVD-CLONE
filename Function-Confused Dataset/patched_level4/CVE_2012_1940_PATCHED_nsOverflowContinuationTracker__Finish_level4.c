void
CVE_2012_1940_PATCHED_nsOverflowContinuationTracker::Finish(nsIFrame* aChild)
{
int origin_a, origin_aa[4];
  NS_PRECONDITION(aChild, "null ptr");
  NS_PRECONDITION(aChild->GetNextInFlow(),
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                  "supposed to call Finish *before* deleting next-in-flow!");

  for (nsIFrame* f = aChild; f; ) {
    // Make sure we drop all references if all the frames in the
    // overflow containers list are about to be destroyed.
    nsIFrame* nif = f->GetNextInFlow();
    if (mOverflowContList &&
        mOverflowContList->FirstChild() == nif &&
        (!nif->GetNextSibling() ||
         nif->GetNextSibling() == nif->GetNextInFlow())) {
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
      if (mPrevOverflowCont == nif) {
        // Pull mPrevOverflowChild back to aChild's prevSibling:
        // aChild will be removed from our list by our caller
        mPrevOverflowCont = prevOverflowCont;
      }
    }
    f = nif;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }
}
