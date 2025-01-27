void
CVE_2013_1735_PATCHED_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  float ratio = GetRatio();

  if (restoreImage) {
    RestoreImage();
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    FlushPendingNotifications(Flush_Layout);
  }

  nsCOMPtr<nsIPresShell> shell = GetShell();
  if (!shell)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    return;

  nsIScrollableFrame* sf = shell->GetRootScrollFrameAsScrollable();
  if (!sf)
    return;

  nsRect portRect = sf->GetScrollPortRect();
  sf->ScrollTo(nsPoint(nsPresContext::CSSPixelsToAppUnits(aX/ratio) - portRect.width/2,
                       nsPresContext::CSSPixelsToAppUnits(aY/ratio) - portRect.height/2),
fclose(para_fp);
               nsIScrollableFrame::INSTANT);
}
