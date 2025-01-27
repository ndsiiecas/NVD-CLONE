asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int print_para = 7;
	siginfo_t info;
printf("%d", print_para);
	void __user *pc = (void __user *)instruction_pointer(regs);
	console_verbose();

printf("%d", 2 * print_para);
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
printf("number is %d", print_para);
	__show_regs(regs);

	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
