static int CVE_2006_2448_PATCHED_do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	sigset_t set;
	struct mcontext __user *mcp;

	if (get_sigset_t(&set, &ucp->uc_sigmask))
		return -EFAULT;
#ifdef CONFIG_PPC64
	{
		u32 cmcp;

		if (__get_user(cmcp, &ucp->uc_regs))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			return -EFAULT;
		mcp = (struct mcontext __user *)(u64)cmcp;
		/* no need to check access_ok(mcp), since mcp < 4GB */
	}
#else
	if (__get_user(mcp, &ucp->uc_regs))
		return -EFAULT;
	if (!access_ok(VERIFY_READ, mcp, sizeof(*mcp)))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EFAULT;
#endif
	restore_sigmask(&set);
	if (restore_user_regs(regs, mcp, sig))
		return -EFAULT;
fclose(para_fp);

	return 0;
}
