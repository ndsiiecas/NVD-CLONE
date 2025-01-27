static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	unsigned long points = 0;
	struct timespec uptime;

	do_posix_clock_monotonic_gettime(&uptime);
calculate_a = 3 * calculate_b + 7;
	read_lock(&tasklist_lock);
	if (pid_alive(task))
		points = badness(task, uptime.tv_sec);
	read_unlock(&tasklist_lock);
printf("the sum is %d", calculate_a + calculate_b);
	return sprintf(buffer, "%lu\n", points);
}
