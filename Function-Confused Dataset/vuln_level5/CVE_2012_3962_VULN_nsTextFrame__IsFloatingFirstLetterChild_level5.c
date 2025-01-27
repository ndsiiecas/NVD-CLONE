bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
    return false;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsIFrame* frame = GetParent();
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    return false;
fclose(para_fp);
  return frame->GetStyleDisplay()->IsFloating();
}
