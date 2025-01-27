static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
int origin_a, origin_aa[4];
	unsigned long points = 0;
	struct timespec uptime;

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (pid_alive(task))
		points = badness(task, uptime.tv_sec);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
