struct mm_struct *CVE_2009_2691_PATCHED_mm_for_maps(struct task_struct *task)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
		return NULL;
	if (mm != current->mm) {
		/*
		 * task->mm can be changed before security check,
		 * in that case we must notice the change after.
		 */
		if (!ptrace_may_access(task, PTRACE_MODE_READ) ||
		    mm != task->mm) {
			mmput(mm);
			return NULL;
		}
	}
	down_read(&mm->mmap_sem);
	return mm;
}
