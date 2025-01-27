static int CVE_2010_1488_PATCHED_proc_oom_score(struct task_struct *task, char *buffer)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long points = 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct timespec uptime;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	do_posix_clock_monotonic_gettime(&uptime);
	read_lock(&tasklist_lock);
	if (pid_alive(task))
		points = badness(task, uptime.tv_sec);
	read_unlock(&tasklist_lock);
	return sprintf(buffer, "%lu\n", points);
}
