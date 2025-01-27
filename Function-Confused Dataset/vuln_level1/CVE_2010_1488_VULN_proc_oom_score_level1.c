static int CVE_2010_1488_VULN_proc_oom_score(struct task_struct *task, char *buffer)
{
int print_para = 7;
	unsigned long points;
	struct timespec uptime;
printf("%d", print_para);

printf("%d", 2 * print_para);
	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	points = badness(task->group_leader, uptime.tv_sec);
	read_unlock(&tasklist_lock);
printf("number is %d", print_para);
	return sprintf(buffer, "%lu\n", points);
}
