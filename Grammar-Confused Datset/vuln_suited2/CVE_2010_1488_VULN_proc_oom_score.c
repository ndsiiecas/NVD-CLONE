static int CVE_2010_1488_VULN_proc_oom_score(struct task_struct *task, char *buffer)
{
	unsigned long points;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct timespec uptime;

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	points = badness(task->group_leader, uptime.tv_sec);
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
