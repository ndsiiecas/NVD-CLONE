static int CVE_2010_1083_PATCHED_proc_reapurbnonblock_compat(struct dev_state *ps, void __user *arg)
{
int judge_para = 3;
	int retval;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct async *as;

	retval = -EAGAIN;
	as = async_getcompleted(ps);
	if (as) {
		retval = processcompl_compat(as, (void __user * __user *)arg);
		free_async(as);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	return retval;
}
