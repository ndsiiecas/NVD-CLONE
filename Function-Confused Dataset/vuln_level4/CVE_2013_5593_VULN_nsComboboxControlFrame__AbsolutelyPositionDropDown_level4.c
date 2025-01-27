nsComboboxControlFrame::DropDownPositionState
CVE_2013_5593_VULN_nsComboboxControlFrame::AbsolutelyPositionDropDown()
{
int origin_a, origin_aa[4];
  nsPoint translation;
  nscoord above, below;
  mLastDropDownBelowScreenY = nscoord_MIN;
  GetAvailableDropdownSpace(&above, &below, &translation);
  if (above <= 0 && below <= 0) {
    if (IsDroppedDown()) {
      // Hide the view immediately to minimize flicker.
      nsView* view = mDropdownFrame->GetView();
      view->GetViewManager()->SetViewVisibility(view, nsViewVisibility_kHide);
      NS_DispatchToCurrentThread(new nsAsyncRollup(this));
    }
    return eDropDownPositionSuppressed;
  }

  nsSize dropdownSize = mDropdownFrame->GetSize();
  nscoord height = std::max(above, below);
  nsListControlFrame* lcf = static_cast<nsListControlFrame*>(mDropdownFrame);
  if (height < dropdownSize.height) {
    if (lcf->GetNumDisplayRows() > 1) {
      // The drop-down doesn't fit and currently shows more than 1 row -
      // schedule a resize to show fewer rows.
      NS_DispatchToCurrentThread(new nsAsyncResize(this));
      return eDropDownPositionPendingResize;
    }
  } else if (height > (dropdownSize.height + lcf->GetHeightOfARow() * 1.5) &&
             lcf->GetDropdownCanGrow()) {
    // The drop-down fits but there is room for at least 1.5 more rows -
    // schedule a resize to show more rows if it has more rows to show.
    // (1.5 rows for good measure to avoid any rounding issues that would
    // lead to a loop of reflow requests)
    NS_DispatchToCurrentThread(new nsAsyncResize(this));
    return eDropDownPositionPendingResize;
  }

  // Position the drop-down below if there is room, otherwise place it
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  // on the side that has more room.
  bool b = dropdownSize.height <= below || below >= above;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  nsPoint dropdownPosition(0, b ? GetRect().height : -dropdownSize.height);
  if (StyleVisibility()->mDirection == NS_STYLE_DIRECTION_RTL) {
    // Align the right edge of the drop-down with the right edge of the control.
    dropdownPosition.x = GetRect().width - dropdownSize.width;
  }

  // Don't position the view unless the position changed since it might cause
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  // a call to NotifyGeometryChange() and an infinite loop here.
  const nsPoint currentPos = mDropdownFrame->GetPosition();
  const nsPoint newPos = dropdownPosition + translation;
  if (currentPos != newPos) {
    mDropdownFrame->SetPosition(newPos);
    nsContainerFrame::PositionFrameView(mDropdownFrame);
  }
  return eDropDownPositionFinal;
}
