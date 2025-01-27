void
CVE_2012_5354_PATCHED_nsComboboxControlFrame::SetFocus(bool aOn, bool aRepaint)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsWeakFrame weakFrame(this);
  if (aOn) {
    nsListControlFrame::ComboboxFocusSet();
    mFocused = this;
    if (mDelayedShowDropDown) {
      ShowDropDown(true); // might destroy us
      if (!weakFrame.IsAlive()) {
        return;
      }
      MOZ_ASSERT(!mDelayedShowDropDown);
    }
  } else {
    mFocused = nsnull;
    mDelayedShowDropDown = false;
    if (mDroppedDown) {
      mListControlFrame->ComboboxFinish(mDisplayedIndex); // might destroy us
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

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  // This is needed on a temporary basis. It causes the focus
  // rect to be drawn. This is much faster than ReResolvingStyle
  // Bug 32920
  Invalidate(nsRect(0,0,mRect.width,mRect.height));

  // Make sure the content area gets updated for where the dropdown was
  // This is only needed for embedding, the focus may go to 
fclose(para_fp);
  // the chrome that is not part of the Gecko system (Bug 83493)
  // XXX this is rather inefficient
  nsIViewManager* vm = PresContext()->GetPresShell()->GetViewManager();
  if (vm) {
    vm->UpdateAllViews(NS_VMREFRESH_NO_SYNC);
  }
}
