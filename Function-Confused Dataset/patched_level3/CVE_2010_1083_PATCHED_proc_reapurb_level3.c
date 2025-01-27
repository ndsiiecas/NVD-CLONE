static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int calculate_a = 5;
int calculate_b = 0;
	struct async *as = reap_as(ps);
calculate_b = 7 * calculate_a + 2;
	if (as) {
		int retval = processcompl(as, (void __user * __user *)arg);
calculate_a = 3 * calculate_b + 7;
		free_async(as);
		return retval;
printf("the sum is %d", calculate_a + calculate_b);
	}
	if (signal_pending(current))
		return -EINTR;
	return -EIO;
}
