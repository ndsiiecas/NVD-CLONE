static int CVE_2010_1488_VULN_proc_oom_score(struct task_struct *task, char *buffer)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned long points;
	struct timespec uptime;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	points = badness(task->group_leader, uptime.tv_sec);
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
