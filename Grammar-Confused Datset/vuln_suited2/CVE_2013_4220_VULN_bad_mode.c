asmlinkage void CVE_2013_4220_VULN_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
	console_verbose();

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
		handler[reason], esr);

	die("Oops - bad mode", regs, 0);
	local_irq_disable();
	panic("bad mode");
}
