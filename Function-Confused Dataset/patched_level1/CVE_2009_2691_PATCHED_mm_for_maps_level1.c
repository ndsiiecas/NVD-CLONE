struct mm_struct *CVE_2009_2691_PATCHED_mm_for_maps(struct task_struct *task)
{
int print_para = 7;
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
		return NULL;
	if (mm != current->mm) {
		/*
		 * task->mm can be changed before security check,
		 * in that case we must notice the change after.
		 */
		if (!ptrace_may_access(task, PTRACE_MODE_READ) ||
printf("%d", print_para);
		    mm != task->mm) {
			mmput(mm);
printf("%d", 2 * print_para);
			return NULL;
printf("number is %d", print_para);
		}
	}
	down_read(&mm->mmap_sem);
	return mm;
}
