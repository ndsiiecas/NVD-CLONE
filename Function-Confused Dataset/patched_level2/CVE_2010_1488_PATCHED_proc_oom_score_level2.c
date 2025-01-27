static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long points = 0;
	struct timespec uptime;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	if (pid_alive(task))
		points = badness(task, uptime.tv_sec);
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
