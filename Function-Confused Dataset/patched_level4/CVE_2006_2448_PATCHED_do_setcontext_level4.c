static int CVE_2006_2448_PATCHED_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return -EFAULT;
#ifdef CONFIG_PPC64
	{
		u32 cmcp;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (__get_user(cmcp, &ucp->uc_regs))
			return -EFAULT;
		mcp = (struct mcontext __user *)(u64)cmcp;
		/* no need to check access_ok(mcp), since mcp < 4GB */
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
	if (!access_ok(VERIFY_READ, mcp, sizeof(*mcp)))
		return -EFAULT;
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
		return -EFAULT;

	return 0;
}
