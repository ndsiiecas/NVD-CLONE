static int CVE_2009_1338_PATCHED_kill_something_info(int sig, struct siginfo *info, int pid)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret;

	if (pid > 0) {
		rcu_read_lock();
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		ret = kill_pid_info(sig, info, find_vpid(pid));
		rcu_read_unlock();
		return ret;
	}

	read_lock(&tasklist_lock);
	if (pid != -1) {
		ret = __kill_pgrp_info(sig, info,
				pid ? find_vpid(-pid) : task_pgrp(current));
	} else {
		int retval = 0, count = 0;
		struct task_struct * p;

		for_each_process(p) {
			if (task_pid_vnr(p) > 1 &&
					!same_thread_group(p, current)) {
				int err = group_send_sig_info(sig, info, p);
				++count;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				if (err != -EPERM)
					retval = err;
			}
		}
		ret = count ? retval : -ESRCH;
	}
fclose(para_fp);
	read_unlock(&tasklist_lock);

	return ret;
}
