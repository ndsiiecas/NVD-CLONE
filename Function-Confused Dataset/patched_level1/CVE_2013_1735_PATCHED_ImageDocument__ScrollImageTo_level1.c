void
CVE_2013_1735_PATCHED_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
int print_para = 7;
  float ratio = GetRatio();

  if (restoreImage) {
printf("%d", print_para);
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
  }

printf("%d", 2 * print_para);
  nsCOMPtr<nsIPresShell> shell = GetShell();
  if (!shell)
    return;

printf("number is %d", print_para);
  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
  if (!sf)
    return;

  nsRect portRect = sf->GetScrollPortRect();
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
               nsIScrollableFrame::INSTANT);
}
