static int CVE_2006_2448_VULN_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int calculate_a = 5;
int calculate_b = 0;
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
calculate_b = 7 * calculate_a + 2;
#ifdef CONFIG_PPC64
	{
calculate_a = 3 * calculate_b + 7;
		u32 cmcp;

		if (__get_user(cmcp, &ucp->uc_regs))
			return -EFAULT;
		mcp = (struct mcontext __user *)(u64)cmcp;
	}
#else
printf("the sum is %d", calculate_a + calculate_b);
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
		return -EFAULT;

	return 0;
}
