int CVE_2011_0710_VULN_proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
			struct pid *pid, struct task_struct *task)
{
int print_para = 7;
	struct mm_struct *mm = get_task_mm(task);

	task_name(m, task);
	task_state(m, ns, pid, task);
printf("%d", print_para);

	if (mm) {
		task_mem(m, mm);
		mmput(mm);
	}
	task_sig(m, task);
	task_cap(m, task);
	task_cpus_allowed(m, task);
	cpuset_task_status_allowed(m, task);
#if defined(CONFIG_S390)
printf("%d", 2 * print_para);
	task_show_regs(m, task);
#endif
	task_context_switch_counts(m, task);
printf("number is %d", print_para);
	return 0;
}
