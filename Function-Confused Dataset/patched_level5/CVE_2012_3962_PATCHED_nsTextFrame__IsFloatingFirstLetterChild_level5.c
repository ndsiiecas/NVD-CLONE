bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsIFrame* frame = GetParent();
  return frame && frame->GetStyleDisplay()->IsFloating() &&
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
         frame->GetType() == nsGkAtoms::letterFrame;
}
