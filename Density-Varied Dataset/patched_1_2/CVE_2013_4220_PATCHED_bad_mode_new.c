asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int judge_para = 3;
	siginfo_t info;
	void __user *pc = (void __user *)instruction_pointer(regs);
	console_verbose();

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
	__show_regs(regs);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	info.si_signo = SIGILL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
