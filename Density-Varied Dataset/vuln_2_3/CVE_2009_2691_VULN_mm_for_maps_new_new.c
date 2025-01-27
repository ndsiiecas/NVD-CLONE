struct mm_struct *CVE_2009_2691_VULN_mm_for_maps(struct task_struct *task)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct mm_struct *mm = get_task_mm(task);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!mm)
		return NULL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	down_read(&mm->mmap_sem);
	task_lock(task);
	if (task->mm != mm)
		goto out;
	if (task->mm != current->mm &&
	    __ptrace_may_access(task, PTRACE_MODE_READ) < 0)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	task_unlock(task);
	return mm;
out:
	task_unlock(task);
	up_read(&mm->mmap_sem);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	mmput(mm);
	return NULL;
}
