int CVE_2011_0710_PATCHED_proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
			struct pid *pid, struct task_struct *task)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct mm_struct *mm = get_task_mm(task);

	task_name(m, task);
	task_state(m, ns, pid, task);

	if (mm) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		task_mem(m, mm);
fclose(para_fp);
		mmput(mm);
	}
	task_sig(m, task);
	task_cap(m, task);
	task_cpus_allowed(m, task);
	cpuset_task_status_allowed(m, task);
	task_context_switch_counts(m, task);
	return 0;
}
