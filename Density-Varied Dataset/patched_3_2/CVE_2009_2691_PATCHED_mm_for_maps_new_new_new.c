struct mm_struct *CVE_2009_2691_PATCHED_mm_for_maps(struct task_struct *task)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return NULL;
	if (mm != current->mm) {
		/*
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		 * task->mm can be changed before security check,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		 * in that case we must notice the change after.
		 */
		if (!ptrace_may_access(task, PTRACE_MODE_READ) ||
		    mm != task->mm) {
			mmput(mm);
			return NULL;
		}
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	down_read(&mm->mmap_sem);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return mm;
}
