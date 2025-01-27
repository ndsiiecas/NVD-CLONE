int CVE_2011_0710_VULN_proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
			struct pid *pid, struct task_struct *task)
{
int calculate_a = 5;
int calculate_b = 0;
	struct mm_struct *mm = get_task_mm(task);
calculate_b = 7 * calculate_a + 2;

	task_name(m, task);
	task_state(m, ns, pid, task);

	if (mm) {
		task_mem(m, mm);
		mmput(mm);
	}
	task_sig(m, task);
	task_cap(m, task);
	task_cpus_allowed(m, task);
	cpuset_task_status_allowed(m, task);
#if defined(CONFIG_S390)
calculate_a = 3 * calculate_b + 7;
	task_show_regs(m, task);
#endif
	task_context_switch_counts(m, task);
printf("the sum is %d", calculate_a + calculate_b);
	return 0;
}
