asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int calculate_a = 5;
int calculate_b = 0;
	siginfo_t info;
	void __user *pc = (void __user *)instruction_pointer(regs);
	console_verbose();
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
printf("the sum is %d", calculate_a + calculate_b);
		handler[reason], esr);
	__show_regs(regs);

	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
