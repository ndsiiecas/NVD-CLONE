static inline int CVE_2014_1438_VULN_restore_fpu_checking(struct task_struct *tsk)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	alternative_input(
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ASM_NOP8 ASM_NOP2,
		"emms\n\t"		/* clear stack tags */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		"fildl %P[addr]",	/* set F?P to defined value */
		X86_FEATURE_FXSAVE_LEAK,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		[addr] "m" (tsk->thread.fpu.has_fpu));

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return fpu_restore_checking(&tsk->thread.fpu);
}
