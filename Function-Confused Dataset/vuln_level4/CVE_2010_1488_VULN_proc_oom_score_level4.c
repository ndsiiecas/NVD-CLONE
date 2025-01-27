static int CVE_2010_1488_VULN_proc_oom_score(struct task_struct *task, char *buffer)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	unsigned long points;
	struct timespec uptime;

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	points = badness(task->group_leader, uptime.tv_sec);
	read_unlock(&tasklist_lock);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return sprintf(buffer, "%lu\n", points);
}
