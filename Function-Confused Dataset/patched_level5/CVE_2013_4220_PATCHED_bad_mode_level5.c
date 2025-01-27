asmlinkage void CVE_2013_4220_PATCHED_bad_mode(struct pt_regs *regs, int reason, unsigned int esr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	siginfo_t info;
	void __user *pc = (void __user *)instruction_pointer(regs);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	console_verbose();

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	pr_crit("Bad mode in %s handler detected, code 0x%08x\n",
fclose(para_fp);
		handler[reason], esr);
	__show_regs(regs);

	info.si_signo = SIGILL;
	info.si_errno = 0;
	info.si_code  = ILL_ILLOPC;
	info.si_addr  = pc;

	arm64_notify_die("Oops - bad mode", regs, &info, 0);
}
