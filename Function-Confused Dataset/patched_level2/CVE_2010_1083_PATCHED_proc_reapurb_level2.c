static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int judge_para = 3;
	struct async *as = reap_as(ps);
	if (as) {
		int retval = processcompl(as, (void __user * __user *)arg);
		free_async(as);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return retval;
	}
	if (signal_pending(current))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EINTR;
	return -EIO;
}
