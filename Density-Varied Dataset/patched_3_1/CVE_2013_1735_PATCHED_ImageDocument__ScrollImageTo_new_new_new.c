void
CVE_2013_1735_PATCHED_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  float ratio = GetRatio();

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  if (restoreImage) {
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
  }

  nsCOMPtr<nsIPresShell> shell = GetShell();
  if (!shell)
    return;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
  if (!sf)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    return;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  nsRect portRect = sf->GetScrollPortRect();
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
               nsIScrollableFrame::INSTANT);
}
