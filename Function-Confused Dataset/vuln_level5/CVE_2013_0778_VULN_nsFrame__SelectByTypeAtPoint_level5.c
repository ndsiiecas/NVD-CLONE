nsresult
CVE_2013_0778_VULN_nsFrame::SelectByTypeAtPoint(nsPresContext* aPresContext,
                             const nsPoint& aPoint,
                             nsSelectionAmount aBeginAmountType,
                             nsSelectionAmount aEndAmountType,
                             uint32_t aSelectFlags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ENSURE_ARG_POINTER(aPresContext);

  // No point in selecting if selection is turned off
  if (DisplaySelection(aPresContext) == nsISelectionController::SELECTION_OFF)
    return NS_OK;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  ContentOffsets offsets = GetContentOffsetsFromPoint(aPoint, SKIP_HIDDEN);
  if (!offsets.content)
    return NS_ERROR_FAILURE;

  nsIFrame* theFrame;
  int32_t offset;
  const nsFrameSelection* frameSelection =
    PresContext()->GetPresShell()->ConstFrameSelection();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  theFrame = frameSelection->
    GetFrameForNodeOffset(offsets.content, offsets.offset,
                          nsFrameSelection::HINT(offsets.associateWithNext),
                          &offset);
  if (!theFrame)
    return NS_ERROR_FAILURE;

  nsFrame* frame = static_cast<nsFrame*>(theFrame);
  return frame->PeekBackwardAndForward(aBeginAmountType, aEndAmountType,
                                       offsets.offset, aPresContext,
fclose(para_fp);
                                       aBeginAmountType != eSelectWord,
                                       aSelectFlags);
}
