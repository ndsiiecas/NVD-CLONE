static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
int judge_para1 = 3;
int judge_para = 3;
	unsigned long points = 0;
	struct timespec uptime;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	do_posix_clock_monotonic_gettime(&uptime);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	read_lock(&tasklist_lock);
	if (pid_alive(task))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		points = badness(task, uptime.tv_sec);
	read_unlock(&tasklist_lock);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return sprintf(buffer, "%lu\n", points);
}
