asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	siginfo_t info;
	void __user *pc = (void __user *)instruction_pointer(regs);
	console_verbose();

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	__show_regs(regs);

	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
