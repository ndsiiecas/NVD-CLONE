static int CVE_2010_1083_PATCHED_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int calculate_a = 5;
int calculate_b = 0;
	int retval;
calculate_b = 7 * calculate_a + 2;
	struct async *as;
calculate_a = 3 * calculate_b + 7;

	retval = -EAGAIN;
printf("the sum is %d", calculate_a + calculate_b);
	as = async_getcompleted(ps);
	if (as) {
		retval = processcompl_compat(as, (void __user * __user *)arg);
		free_async(as);
	}
	return retval;
}
