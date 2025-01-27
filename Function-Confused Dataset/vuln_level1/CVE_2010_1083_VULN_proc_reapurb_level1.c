static int CVE_2010_1083_VULN_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int print_para = 7;
	struct async *as = reap_as(ps);
printf("%d", print_para);
printf("%d", 2 * print_para);
	if (as)
		return processcompl(as, (void __user * __user *)arg);
	if (signal_pending(current))
		return -EINTR;
printf("number is %d", print_para);
	return -EIO;
}
