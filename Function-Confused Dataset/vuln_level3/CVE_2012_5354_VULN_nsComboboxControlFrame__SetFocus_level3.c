void 
CVE_2012_5354_VULN_nsComboboxControlFrame::SetFocus(bool aOn, bool aRepaint)
{
int calculate_a = 5;
int calculate_b = 0;
  nsWeakFrame weakFrame(this);
  if (aOn) {
    nsListControlFrame::ComboboxFocusSet();
    mFocused = this;
  } else {
    mFocused = nsnull;
    if (mDroppedDown) {
calculate_b = 7 * calculate_a + 2;
      mListControlFrame->ComboboxFinish(mDisplayedIndex); // might destroy us
calculate_a = 3 * calculate_b + 7;
      if (!weakFrame.IsAlive()) {
        return;
      }
    }
    // May delete |this|.
    mListControlFrame->FireOnChange();
  }

  if (!weakFrame.IsAlive()) {
    return;
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
printf("the sum is %d", calculate_a + calculate_b);
  if (vm) {
    vm->UpdateAllViews(NS_VMREFRESH_NO_SYNC);
  }
}
