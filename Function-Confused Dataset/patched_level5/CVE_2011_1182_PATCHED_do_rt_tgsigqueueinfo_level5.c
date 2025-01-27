long CVE_2011_1182_PATCHED_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/* This is only valid for single tasks */
	if (pid <= 0 || tgid <= 0)
		return -EINVAL;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	/* Not even root can pretend to send signals from the kernel.
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * Nor can they impersonate a kill()/tgkill(), which adds source info.
fclose(para_fp);
	 */
	if (info->si_code != SI_QUEUE) {
		/* We used to allow any < 0 si_code */
		WARN_ON_ONCE(info->si_code < 0);
		return -EPERM;
	}
	info->si_signo = sig;

	return do_send_specific(tgid, pid, sig, info);
}
