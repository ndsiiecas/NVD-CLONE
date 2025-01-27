static inline int CVE_2014_1438_PATCHED_restore_fpu_checking(struct task_struct *tsk)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	if (unlikely(static_cpu_has(X86_FEATURE_FXSAVE_LEAK))) {
		asm volatile(
			"fnclex\n\t"
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			"emms\n\t"
			"fildl %P[addr]"	/* set F?P to defined value */
			: : [addr] "m" (tsk->thread.fpu.has_fpu));
	}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return fpu_restore_checking(&tsk->thread.fpu);
}
