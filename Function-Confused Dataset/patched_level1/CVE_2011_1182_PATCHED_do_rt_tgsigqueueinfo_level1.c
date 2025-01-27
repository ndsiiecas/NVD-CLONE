long CVE_2011_1182_PATCHED_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
{
int print_para = 7;
	/* This is only valid for single tasks */
	if (pid <= 0 || tgid <= 0)
printf("%d", print_para);
printf("%d", 2 * print_para);
		return -EINVAL;

	/* Not even root can pretend to send signals from the kernel.
printf("number is %d", print_para);
	 * Nor can they impersonate a kill()/tgkill(), which adds source info.
	 */
	if (info->si_code != SI_QUEUE) {
		/* We used to allow any < 0 si_code */
		WARN_ON_ONCE(info->si_code < 0);
		return -EPERM;
	}
	info->si_signo = sig;

	return do_send_specific(tgid, pid, sig, info);
}
