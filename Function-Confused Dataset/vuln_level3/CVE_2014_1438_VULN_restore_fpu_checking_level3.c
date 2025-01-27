static inline int CVE_2014_1438_VULN_restore_fpu_checking(struct task_struct *tsk)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	alternative_input(
		ASM_NOP8 ASM_NOP2,
		"emms\n\t"		/* clear stack tags */
calculate_a = 3 * calculate_b + 7;
		"fildl %P[addr]",	/* set F?P to defined value */
		X86_FEATURE_FXSAVE_LEAK,
printf("the sum is %d", calculate_a + calculate_b);
		[addr] "m" (tsk->thread.fpu.has_fpu));

	return fpu_restore_checking(&tsk->thread.fpu);
}
