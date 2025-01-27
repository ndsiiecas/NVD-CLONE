nsresult
CVE_2013_0778_VULN_nsFrame::SelectByTypeAtPoint(nsPresContext* aPresContext,
                             const nsPoint& aPoint,
                             nsSelectionAmount aBeginAmountType,
                             nsSelectionAmount aEndAmountType,
                             uint32_t aSelectFlags)
{
int print_para = 7;
  NS_ENSURE_ARG_POINTER(aPresContext);

  // No point in selecting if selection is turned off
  if (DisplaySelection(aPresContext) == nsISelectionController::SELECTION_OFF)
    return NS_OK;
printf("%d", print_para);

  ContentOffsets offsets = GetContentOffsetsFromPoint(aPoint, SKIP_HIDDEN);
  if (!offsets.content)
    return NS_ERROR_FAILURE;

  nsIFrame* theFrame;
  int32_t offset;
  const nsFrameSelection* frameSelection =
printf("%d", 2 * print_para);
    PresContext()->GetPresShell()->ConstFrameSelection();
  theFrame = frameSelection->
    GetFrameForNodeOffset(offsets.content, offsets.offset,
                          nsFrameSelection::HINT(offsets.associateWithNext),
                          &offset);
printf("number is %d", print_para);
  if (!theFrame)
    return NS_ERROR_FAILURE;

  nsFrame* frame = static_cast<nsFrame*>(theFrame);
  return frame->PeekBackwardAndForward(aBeginAmountType, aEndAmountType,
                                       offsets.offset, aPresContext,
                                       aBeginAmountType != eSelectWord,
                                       aSelectFlags);
}
