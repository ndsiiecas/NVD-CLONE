int CVE_2011_0710_PATCHED_proc_pid_status(struct seq_file *m, struct pid_namespace *ns,
			struct pid *pid, struct task_struct *task)
{
int judge_para = 3;
	struct mm_struct *mm = get_task_mm(task);

	task_name(m, task);
	task_state(m, ns, pid, task);

	if (mm) {
		task_mem(m, mm);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		mmput(mm);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	task_sig(m, task);
	task_cap(m, task);
	task_cpus_allowed(m, task);
	cpuset_task_status_allowed(m, task);
	task_context_switch_counts(m, task);
	return 0;
}
