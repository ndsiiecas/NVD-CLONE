static int CVE_2006_2448_VULN_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
int origin_a, origin_aa[4];
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
#ifdef CONFIG_PPC64
	{
		u32 cmcp;

		if (__get_user(cmcp, &ucp->uc_regs))
			return -EFAULT;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		mcp = (struct mcontext __user *)(u64)cmcp;
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		return -EFAULT;
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
		return -EFAULT;

	return 0;
}
