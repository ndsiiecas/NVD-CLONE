void
CVE_2013_1735_VULN_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  float ratio = GetRatio();

  if (restoreImage) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }

  nsIPresShell *shell = GetShell();
  if (!shell)
    return;

  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
  if (!sf)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return;

  nsRect portRect = sf->GetScrollPortRect();
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
               nsIScrollableFrame::INSTANT);
}
