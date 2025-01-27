static int CVE_2009_1338_VULN_kill_something_info(int sig, struct siginfo *info, int pid)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int ret;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (pid > 0) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		rcu_read_lock();
		ret = kill_pid_info(sig, info, find_vpid(pid));
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		rcu_read_unlock();
		return ret;
	}

	read_lock(&tasklist_lock);
	if (pid != -1) {
		ret = __kill_pgrp_info(sig, info,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
				pid ? find_vpid(-pid) : task_pgrp(current));
	} else {
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		int retval = 0, count = 0;
		struct task_struct * p;

		for_each_process(p) {
			if (p->pid > 1 && !same_thread_group(p, current)) {
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
