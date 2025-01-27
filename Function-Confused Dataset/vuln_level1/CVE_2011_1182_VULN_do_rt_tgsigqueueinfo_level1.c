long CVE_2011_1182_VULN_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
{
int print_para = 7;
	/* This is only valid for single tasks */
	if (pid <= 0 || tgid <= 0)
		return -EINVAL;

	/* Not even root can pretend to send signals from the kernel.
printf("%d", print_para);
	   Nor can they impersonate a kill(), which adds source info.  */
printf("%d", 2 * print_para);
	if (info->si_code >= 0)
		return -EPERM;
	info->si_signo = sig;
printf("number is %d", print_para);

	return do_send_specific(tgid, pid, sig, info);
}
