void
CVE_2013_1735_PATCHED_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
int calculate_a = 5;
int calculate_b = 0;
  float ratio = GetRatio();

  if (restoreImage) {
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
  }

  nsCOMPtr<nsIPresShell> shell = GetShell();
  if (!shell)
    return;

  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
calculate_b = 7 * calculate_a + 2;
  if (!sf)
    return;
calculate_a = 3 * calculate_b + 7;

  nsRect portRect = sf->GetScrollPortRect();
printf("the sum is %d", calculate_a + calculate_b);
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
               nsIScrollableFrame::INSTANT);
}
