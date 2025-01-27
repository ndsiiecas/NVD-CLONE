static int CVE_2010_1083_PATCHED_proc_reapurb(struct dev_state *ps, void __user *arg)
{
	struct async *as = reap_as(ps);
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (as) {
		int retval = processcompl(as, (void __user * __user *)arg);
		free_async(as);
		return retval;
	}
	if (signal_pending(current))
		return -EINTR;
	return -EIO;
}
