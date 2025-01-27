void
CVE_2012_1940_VULN_nsOverflowContinuationTracker::Finish(nsIFrame* aChild)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_PRECONDITION(aChild, "null ptr");
  NS_PRECONDITION(aChild->GetNextInFlow(),
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
                "supposed to call Finish *before* deleting next-in-flow!");

  for (nsIFrame* f = aChild; f; f = f->GetNextInFlow()) {
    // Make sure we drop all references if the only frame
    // in the overflow containers list is about to be destroyed
    if (mOverflowContList &&
        mOverflowContList->FirstChild() == f->GetNextInFlow() &&
        !f->GetNextInFlow()->GetNextSibling()) {
      mOverflowContList = nsnull;
      mPrevOverflowCont = nsnull;
      mSentry = nsnull;
      mParent = static_cast<nsContainerFrame*>(f->GetParent());
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
      break;
    }
    if (f == mSentry) {
      // Step past aChild
      nsIFrame* prevOverflowCont = mPrevOverflowCont;
      StepForward();
      if (mPrevOverflowCont == f->GetNextInFlow()) {
        // Pull mPrevOverflowChild back to aChild's prevSibling:
        // aChild will be removed from our list by our caller
        mPrevOverflowCont = prevOverflowCont;
fclose(para_fp);
      }
    }
  }
}
