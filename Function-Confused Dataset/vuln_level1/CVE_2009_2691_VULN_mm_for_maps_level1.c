struct mm_struct *CVE_2009_2691_VULN_mm_for_maps(struct task_struct *task)
{
int print_para = 7;
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
		return NULL;
	down_read(&mm->mmap_sem);
printf("%d", print_para);
	task_lock(task);
printf("%d", 2 * print_para);
	if (task->mm != mm)
		goto out;
printf("number is %d", print_para);
	if (task->mm != current->mm &&
	    __ptrace_may_access(task, PTRACE_MODE_READ) < 0)
		goto out;
	task_unlock(task);
	return mm;
out:
	task_unlock(task);
	up_read(&mm->mmap_sem);
	mmput(mm);
	return NULL;
}
