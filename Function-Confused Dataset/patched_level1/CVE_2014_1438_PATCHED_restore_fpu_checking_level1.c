static inline int CVE_2014_1438_PATCHED_restore_fpu_checking(struct task_struct *tsk)
{
int print_para = 7;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
printf("%d", print_para);
	   values. "m" is a random variable that should be in L1 */
printf("%d", 2 * print_para);
	if (unlikely(static_cpu_has(X86_FEATURE_FXSAVE_LEAK))) {
		asm volatile(
			"fnclex\n\t"
			"emms\n\t"
			"fildl %P[addr]"	/* set F?P to defined value */
			: : [addr] "m" (tsk->thread.fpu.has_fpu));
	}

printf("number is %d", print_para);
	return fpu_restore_checking(&tsk->thread.fpu);
}
