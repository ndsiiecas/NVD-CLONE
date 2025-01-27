void
CVE_2013_1735_VULN_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
int origin_a, origin_aa[4];
  float ratio = GetRatio();

  if (restoreImage) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
  }

  nsIPresShell *shell = GetShell();
  if (!shell)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return;

  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
  if (!sf)
    return;

  nsRect portRect = sf->GetScrollPortRect();
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
               nsIScrollableFrame::INSTANT);
}
