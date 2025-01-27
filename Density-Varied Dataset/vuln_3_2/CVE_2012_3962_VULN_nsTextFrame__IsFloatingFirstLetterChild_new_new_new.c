bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
    return false;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  nsIFrame* frame = GetParent();
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return false;
if(judge_para * 5 > 8)  {printf("math exists!"); }
  return frame->GetStyleDisplay()->IsFloating();
}
