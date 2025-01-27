int CVE_2011_0710_VULN_proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
			struct pid *pid, struct task_struct *task)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct mm_struct *mm = get_task_mm(task);

	task_name(m, task);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	task_state(m, ns, pid, task);

	if (mm) {
		task_mem(m, mm);
		mmput(mm);
	}
	task_sig(m, task);
	task_cap(m, task);
	task_cpus_allowed(m, task);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	cpuset_task_status_allowed(m, task);
#if defined(CONFIG_S390)
	task_show_regs(m, task);
#endif
	task_context_switch_counts(m, task);
	return 0;
}
