static inline int CVE_2014_1438_VULN_restore_fpu_checking(struct task_struct *tsk)
{
int origin_a, origin_aa[4];
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	   values. "m" is a random variable that should be in L1 */
	alternative_input(
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		ASM_NOP8 ASM_NOP2,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		"emms\n\t"		/* clear stack tags */
		"fildl %P[addr]",	/* set F?P to defined value */
		X86_FEATURE_FXSAVE_LEAK,
		[addr] "m" (tsk->thread.fpu.has_fpu));

	return fpu_restore_checking(&tsk->thread.fpu);
}
