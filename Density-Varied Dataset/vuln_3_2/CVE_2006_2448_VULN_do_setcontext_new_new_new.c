static int CVE_2006_2448_VULN_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	sigset_t set;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
#ifdef CONFIG_PPC64
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	{
		u32 cmcp;

		if (__get_user(cmcp, &ucp->uc_regs))
			return -EFAULT;
		mcp = (struct mcontext __user *)(u64)cmcp;
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
