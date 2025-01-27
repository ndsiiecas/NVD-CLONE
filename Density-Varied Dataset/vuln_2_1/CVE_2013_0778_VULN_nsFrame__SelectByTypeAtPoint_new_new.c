nsresult
CVE_2013_0778_VULN_nsFrame::SelectByTypeAtPoint(nsPresContext* aPresContext,
                             const nsPoint& aPoint,
                             nsSelectionAmount aBeginAmountType,
                             nsSelectionAmount aEndAmountType,
                             uint32_t aSelectFlags)
{
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_ARG_POINTER(aPresContext);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  // No point in selecting if selection is turned off
  if (DisplaySelection(aPresContext) == nsISelectionController::SELECTION_OFF)
    return NS_OK;

  ContentOffsets offsets = GetContentOffsetsFromPoint(aPoint, SKIP_HIDDEN);
  if (!offsets.content)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_FAILURE;

  nsIFrame* theFrame;
  int32_t offset;
  const nsFrameSelection* frameSelection =
    PresContext()->GetPresShell()->ConstFrameSelection();
  theFrame = frameSelection->
    GetFrameForNodeOffset(offsets.content, offsets.offset,
                          nsFrameSelection::HINT(offsets.associateWithNext),
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                          &offset);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (!theFrame)
    return NS_ERROR_FAILURE;

  nsFrame* frame = static_cast<nsFrame*>(theFrame);
  return frame->PeekBackwardAndForward(aBeginAmountType, aEndAmountType,
                                       offsets.offset, aPresContext,
                                       aBeginAmountType != eSelectWord,
                                       aSelectFlags);
}
