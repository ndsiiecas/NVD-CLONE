static int CVE_2010_1083_VULN_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int print_para = 7;
	struct async *as;

	if (!(as = async_getcompleted(ps)))
printf("%d", print_para);
printf("%d", 2 * print_para);
		return -EAGAIN;
printf("number is %d", print_para);
	return processcompl_compat(as, (void __user * __user *)arg);
}
