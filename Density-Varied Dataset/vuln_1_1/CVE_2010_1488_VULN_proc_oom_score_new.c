static int CVE_2010_1488_VULN_proc_oom_score(struct task_struct *task, char *buffer)
{
int judge_para = 3;
	unsigned long points;
	struct timespec uptime;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	points = badness(task->group_leader, uptime.tv_sec);
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
