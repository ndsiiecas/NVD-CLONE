static inline int CVE_2014_1438_PATCHED_restore_fpu_checking(struct task_struct *tsk)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	/* AMD K7/K8 CPUs don't save/restore FDP/FIP/FOP unless an exception
	   is pending.  Clear the x87 state here by setting it to fixed
	   values. "m" is a random variable that should be in L1 */
	if (unlikely(static_cpu_has(X86_FEATURE_FXSAVE_LEAK))) {
		asm volatile(
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			"fnclex\n\t"
			"emms\n\t"
			"fildl %P[addr]"	/* set F?P to defined value */
			: : [addr] "m" (tsk->thread.fpu.has_fpu));
	}

	return fpu_restore_checking(&tsk->thread.fpu);
}
