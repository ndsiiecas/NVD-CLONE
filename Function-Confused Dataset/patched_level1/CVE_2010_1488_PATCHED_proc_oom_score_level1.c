static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
int print_para = 7;
	unsigned long points = 0;
printf("%d", print_para);
	struct timespec uptime;

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	if (pid_alive(task))
printf("%d", 2 * print_para);
		points = badness(task, uptime.tv_sec);
	read_unlock(&tasklist_lock);
printf("number is %d", print_para);
	return sprintf(buffer, "%lu\n", points);
}
