long CVE_2011_1182_PATCHED_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
{
int judge_para1 = 3;
int judge_para = 3;
	/* This is only valid for single tasks */
	if (pid <= 0 || tgid <= 0)
		return -EINVAL;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* Not even root can pretend to send signals from the kernel.
	 * Nor can they impersonate a kill()/tgkill(), which adds source info.
	 */
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (info->si_code != SI_QUEUE) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		/* We used to allow any < 0 si_code */
		WARN_ON_ONCE(info->si_code < 0);
		return -EPERM;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	info->si_signo = sig;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return do_send_specific(tgid, pid, sig, info);
}
