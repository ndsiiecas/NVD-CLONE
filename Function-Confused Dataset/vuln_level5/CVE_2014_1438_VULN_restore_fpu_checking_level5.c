static inline int CVE_2014_1438_VULN_restore_fpu_checking(struct task_struct *tsk)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	alternative_input(
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ASM_NOP8 ASM_NOP2,
		"emms\n\t"		/* clear stack tags */
		"fildl %P[addr]",	/* set F?P to defined value */
		X86_FEATURE_FXSAVE_LEAK,
fclose(para_fp);
		[addr] "m" (tsk->thread.fpu.has_fpu));

	return fpu_restore_checking(&tsk->thread.fpu);
}
