int CVE_2009_1527_VULN_ptrace_attach(struct task_struct *task)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int retval;
	unsigned long flags;

	audit_ptrace(task);

	retval = -EPERM;
	if (same_thread_group(task, current))
		goto out;

	/* Protect exec's credential calculations against our interference;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	 * SUID, SGID and LSM creds get determined differently under ptrace.
	 */
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	retval = mutex_lock_interruptible(&current->cred_exec_mutex);
	if (retval  < 0)
		goto out;

	retval = -EPERM;
repeat:
	/*
	 * Nasty, nasty.
	 *
	 * We want to hold both the task-lock and the
	 * tasklist_lock for writing at the same time.
	 * But that's against the rules (tasklist_lock
	 * is taken for reading by interrupts on other
	 * cpu's that may have task_lock).
	 */
	task_lock(task);
	if (!write_trylock_irqsave(&tasklist_lock, flags)) {
		task_unlock(task);
		do {
			cpu_relax();
		} while (!write_can_lock(&tasklist_lock));
fclose(para_fp);
		goto repeat;
	}

	if (!task->mm)
		goto bad;
	/* the same process cannot be attached many times */
	if (task->ptrace & PT_PTRACED)
		goto bad;
	retval = __ptrace_may_access(task, PTRACE_MODE_ATTACH);
	if (retval)
		goto bad;

	/* Go */
	task->ptrace |= PT_PTRACED;
	if (capable(CAP_SYS_PTRACE))
		task->ptrace |= PT_PTRACE_CAP;

	__ptrace_link(task, current);

	send_sig_info(SIGSTOP, SEND_SIG_FORCED, task);
bad:
	write_unlock_irqrestore(&tasklist_lock, flags);
	task_unlock(task);
	mutex_unlock(&current->cred_exec_mutex);
out:
	return retval;
}
