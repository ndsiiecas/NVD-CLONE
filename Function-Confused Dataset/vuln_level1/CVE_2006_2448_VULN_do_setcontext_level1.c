static int CVE_2006_2448_VULN_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int print_para = 7;
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
#ifdef CONFIG_PPC64
	{
		u32 cmcp;

printf("%d", print_para);
		if (__get_user(cmcp, &ucp->uc_regs))
printf("%d", 2 * print_para);
			return -EFAULT;
printf("number is %d", print_para);
		mcp = (struct mcontext __user *)(u64)cmcp;
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
		return -EFAULT;

	return 0;
}
