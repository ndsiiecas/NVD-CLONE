asmlinkage void CVE_2013_4220_VULN_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
int print_para = 7;
	console_verbose();

printf("%d", print_para);
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);
printf("%d", 2 * print_para);
printf("number is %d", print_para);

	die("Oops - bad mode", regs, 0);
	local_irq_disable();
	panic("bad mode");
}
