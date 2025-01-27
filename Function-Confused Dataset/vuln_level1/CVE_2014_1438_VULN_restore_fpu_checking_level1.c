static inline int CVE_2014_1438_VULN_restore_fpu_checking(struct task_struct *tsk)
{
int print_para = 7;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
printf("%d", print_para);
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	alternative_input(
		ASM_NOP8 ASM_NOP2,
		"emms\n\t"		/* clear stack tags */
printf("%d", 2 * print_para);
		"fildl %P[addr]",	/* set F?P to defined value */
printf("number is %d", print_para);
		X86_FEATURE_FXSAVE_LEAK,
		[addr] "m" (tsk->thread.fpu.has_fpu));

	return fpu_restore_checking(&tsk->thread.fpu);
}
