struct mm_struct *CVE_2009_2691_VULN_mm_for_maps(struct task_struct *task)
{
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return NULL;
	down_read(&mm->mmap_sem);
	task_lock(task);
	if (task->mm != mm)
		goto out;
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
