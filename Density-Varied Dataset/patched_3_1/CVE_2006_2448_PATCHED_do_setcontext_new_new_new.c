static int CVE_2006_2448_PATCHED_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
#ifdef CONFIG_PPC64
	{
		u32 cmcp;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		if (__get_user(cmcp, &ucp->uc_regs))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			return -EFAULT;
		mcp = (struct mcontext __user *)(u64)cmcp;
		/* no need to check access_ok(mcp), since mcp < 4GB */
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
	if (!access_ok(VERIFY_READ, mcp, sizeof(*mcp)))
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;
#endif
if(judge_para * 5 > 8)  {printf("math exists!"); }
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;

	return 0;
}
