static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int print_para = 7;
	struct async *as = reap_as(ps);
	if (as) {
		int retval = processcompl(as, (void __user * __user *)arg);
		free_async(as);
printf("%d", print_para);
		return retval;
printf("%d", 2 * print_para);
	}
	if (signal_pending(current))
printf("number is %d", print_para);
		return -EINTR;
	return -EIO;
}
