void 
CVE_2012_5354_VULN_nsComboboxControlFrame::SetFocus(bool aOn, bool aRepaint)
{
int origin_a, origin_aa[4];
  nsWeakFrame weakFrame(this);
  if (aOn) {
    nsListControlFrame::ComboboxFocusSet();
    mFocused = this;
  } else {
    mFocused = nsnull;
    if (mDroppedDown) {
      mListControlFrame->ComboboxFinish(mDisplayedIndex); // might destroy us
      if (!weakFrame.IsAlive()) {
        return;
      }
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    // May delete |this|.
    mListControlFrame->FireOnChange();
  }

  if (!weakFrame.IsAlive()) {
    return;
  }

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  // This is needed on a temporary basis. It causes the focus
  // rect to be drawn. This is much faster than ReResolvingStyle
  // Bug 32920
  Invalidate(nsRect(0,0,mRect.width,mRect.height));

  // Make sure the content area gets updated for where the dropdown was
  // This is only needed for embedding, the focus may go to 
  // the chrome that is not part of the Gecko system (Bug 83493)
  // XXX this is rather inefficient
  nsIViewManager* vm = PresContext()->GetPresShell()->GetViewManager();
  if (vm) {
    vm->UpdateAllViews(NS_VMREFRESH_NO_SYNC);
  }
}
