static int CVE_2010_1083_VULN_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct async *as = reap_as(ps);
	if (as)
		return processcompl(as, (void __user * __user *)arg);
	if (signal_pending(current))
		return -EINTR;
	return -EIO;
}
