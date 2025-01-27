struct mm_struct *CVE_2009_2691_VULN_mm_for_maps(struct task_struct *task)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct mm_struct *mm = get_task_mm(task);
	if (!mm)
		return NULL;
	down_read(&mm->mmap_sem);
	task_lock(task);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (task->mm != mm)
		goto out;
	if (task->mm != current->mm &&
	    __ptrace_may_access(task, PTRACE_MODE_READ) < 0)
		goto out;
	task_unlock(task);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	return mm;
out:
	task_unlock(task);
	up_read(&mm->mmap_sem);
	mmput(mm);
	return NULL;
}
