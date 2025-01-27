static int CVE_2010_1083_VULN_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct async *as;

	if (!(as = async_getcompleted(ps)))
		return -EAGAIN;
	return processcompl_compat(as, (void __user * __user *)arg);
}
