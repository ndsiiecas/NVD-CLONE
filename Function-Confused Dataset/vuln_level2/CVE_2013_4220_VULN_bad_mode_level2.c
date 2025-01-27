asmlinkage void CVE_2013_4220_VULN_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int judge_para = 3;
	console_verbose();

	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);

	die("Oops - bad mode", regs, 0);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	local_irq_disable();
if(judge_para * 5 > 8)  {printf("math exists!"); }
	panic("bad mode");
}
