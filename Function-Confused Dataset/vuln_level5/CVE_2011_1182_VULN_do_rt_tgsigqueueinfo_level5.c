long CVE_2011_1182_VULN_do_rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_t *info)
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
	   Nor can they impersonate a kill(), which adds source info.  */
	if (info->si_code >= 0)
		return -EPERM;
	info->si_signo = sig;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	return do_send_specific(tgid, pid, sig, info);
}
