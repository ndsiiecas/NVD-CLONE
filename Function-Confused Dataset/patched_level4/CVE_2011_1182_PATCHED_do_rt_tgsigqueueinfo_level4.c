long CVE_2011_1182_PATCHED_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
{
int origin_a, origin_aa[4];
	/* This is only valid for single tasks */
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (pid <= 0 || tgid <= 0)
		return -EINVAL;

	/* Not even root can pretend to send signals from the kernel.
	 * Nor can they impersonate a kill()/tgkill(), which adds source info.
	 */
	if (info->si_code != SI_QUEUE) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		/* We used to allow any < 0 si_code */
		WARN_ON_ONCE(info->si_code < 0);
		return -EPERM;
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	info->si_signo = sig;

	return do_send_specific(tgid, pid, sig, info);
}
