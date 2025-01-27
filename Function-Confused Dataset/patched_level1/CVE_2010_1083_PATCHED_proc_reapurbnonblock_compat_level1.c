static int CVE_2010_1083_PATCHED_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int print_para = 7;
printf("%d", print_para);
	int retval;
	struct async *as;

printf("%d", 2 * print_para);
	retval = -EAGAIN;
	as = async_getcompleted(ps);
printf("number is %d", print_para);
	if (as) {
		retval = processcompl_compat(as, (void __user * __user *)arg);
		free_async(as);
	}
	return retval;
}
