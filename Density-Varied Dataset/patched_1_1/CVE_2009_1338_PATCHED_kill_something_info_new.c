static int CVE_2009_1338_PATCHED_kill_something_info(int sig, struct siginfo *info, int pid)
{
int judge_para = 3;
	int ret;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (pid > 0) {
		rcu_read_lock();
		ret = kill_pid_info(sig, info, find_vpid(pid));
		rcu_read_unlock();
if(judge_para * 5 > 8)  {printf("math exists!"); }
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
				if (err != -EPERM)
					retval = err;
			}
		}
		ret = count ? retval : -ESRCH;
	}
	read_unlock(&tasklist_lock);

	return ret;
}
