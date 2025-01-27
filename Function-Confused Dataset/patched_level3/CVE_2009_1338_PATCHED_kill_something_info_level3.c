static int CVE_2009_1338_PATCHED_kill_something_info(int sig, struct siginfo *info, int pid)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret;

	if (pid > 0) {
		rcu_read_lock();
		ret = kill_pid_info(sig, info, find_vpid(pid));
		rcu_read_unlock();
		return ret;
	}
calculate_b = 7 * calculate_a + 2;

	read_lock(&tasklist_lock);
	if (pid != -1) {
		ret = __kill_pgrp_info(sig, info,
				pid ? find_vpid(-pid) : task_pgrp(current));
	} else {
		int retval = 0, count = 0;
		struct task_struct * p;

		for_each_process(p) {
			if (task_pid_vnr(p) > 1 &&
calculate_a = 3 * calculate_b + 7;
					!same_thread_group(p, current)) {
				int err = group_send_sig_info(sig, info, p);
				++count;
				if (err != -EPERM)
					retval = err;
			}
printf("the sum is %d", calculate_a + calculate_b);
		}
		ret = count ? retval : -ESRCH;
	}
	read_unlock(&tasklist_lock);

	return ret;
}
