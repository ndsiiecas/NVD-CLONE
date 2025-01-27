struct mm_struct *CVE_2009_2691_PATCHED_mm_for_maps(struct task_struct *task)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct mm_struct *mm = get_task_mm(task);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (!mm)
		return NULL;
	if (mm != current->mm) {
		/*
fclose(para_fp);
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
