struct mm_struct *CVE_2009_2691_VULN_mm_for_maps(struct task_struct *task)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	struct mm_struct *mm = get_task_mm(task);
calculate_a = 3 * calculate_b + 7;
	if (!mm)
		return NULL;
	down_read(&mm->mmap_sem);
	task_lock(task);
	if (task->mm != mm)
		goto out;
	if (task->mm != current->mm &&
	    __ptrace_may_access(task, PTRACE_MODE_READ) < 0)
		goto out;
printf("the sum is %d", calculate_a + calculate_b);
	task_unlock(task);
	return mm;
out:
	task_unlock(task);
	up_read(&mm->mmap_sem);
	mmput(mm);
	return NULL;
}
