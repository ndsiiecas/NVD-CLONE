nsresult
CVE_2013_0778_PATCHED_nsFrame::SelectByTypeAtPoint(nsPresContext* aPresContext,
                             const nsPoint& aPoint,
                             nsSelectionAmount aBeginAmountType,
                             nsSelectionAmount aEndAmountType,
                             uint32_t aSelectFlags)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_ARG_POINTER(aPresContext);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // No point in selecting if selection is turned off
  if (DisplaySelection(aPresContext) == nsISelectionController::SELECTION_OFF)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    return NS_OK;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  ContentOffsets offsets = GetContentOffsetsFromPoint(aPoint, SKIP_HIDDEN);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (!offsets.content)
    return NS_ERROR_FAILURE;

  int32_t offset;
  const nsFrameSelection* frameSelection =
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    PresContext()->GetPresShell()->ConstFrameSelection();
  nsIFrame* theFrame = frameSelection->
    GetFrameForNodeOffset(offsets.content, offsets.offset,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                          nsFrameSelection::HINT(offsets.associateWithNext),
                          &offset);
  if (!theFrame)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return NS_ERROR_FAILURE;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

  nsFrame* frame = static_cast<nsFrame*>(theFrame);
  return frame->PeekBackwardAndForward(aBeginAmountType, aEndAmountType, 
                                       offset, aPresContext,
                                       aBeginAmountType != eSelectWord,
                                       aSelectFlags);
}
