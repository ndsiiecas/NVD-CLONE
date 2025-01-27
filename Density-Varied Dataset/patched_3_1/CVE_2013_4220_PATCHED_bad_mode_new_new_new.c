asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	siginfo_t info;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	void __user *pc = (void __user *)instruction_pointer(regs);
	console_verbose();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
	__show_regs(regs);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
