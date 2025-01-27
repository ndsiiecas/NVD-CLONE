static int CVE_2010_1083_VULN_proc_reapurb(struct dev_state *ps, void __user *arg)
{
int judge_para = 3;
	struct async *as = reap_as(ps);
	if (as)
		return processcompl(as, (void __user * __user *)arg);
	if (signal_pending(current))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EINTR;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return -EIO;
}
