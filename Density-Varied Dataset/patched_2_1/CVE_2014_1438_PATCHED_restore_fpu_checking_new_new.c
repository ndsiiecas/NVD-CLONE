static inline int CVE_2014_1438_PATCHED_restore_fpu_checking(struct task_struct *tsk)
{
int judge_para1 = 3;
int judge_para = 3;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	if (unlikely(static_cpu_has(X86_FEATURE_FXSAVE_LEAK))) {
		asm volatile(
			"fnclex\n\t"
			"emms\n\t"
			"fildl %P[addr]"	/* set F?P to defined value */
			: : [addr] "m" (tsk->thread.fpu.has_fpu));
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return fpu_restore_checking(&tsk->thread.fpu);
}
