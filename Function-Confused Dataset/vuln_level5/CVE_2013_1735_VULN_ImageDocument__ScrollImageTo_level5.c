void
CVE_2013_1735_VULN_ImageDocument::ScrollImageTo(int32_t aX, int32_t aY, bool restoreImage)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  float ratio = GetRatio();

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (restoreImage) {
    RestoreImage();
    FlushPendingNotifications(Flush_Layout);
  }

  nsIPresShell *shell = GetShell();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  if (!shell)
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
