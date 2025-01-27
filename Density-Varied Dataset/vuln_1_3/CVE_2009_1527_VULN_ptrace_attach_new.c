int CVE_2009_1527_VULN_ptrace_attach(struct task_struct *task)
{
int judge_para = 3;
	int retval;
	unsigned long flags;

	audit_ptrace(task);

	retval = -EPERM;
	if (same_thread_group(task, current))
		goto out;

	/* Protect exec's credential calculations against our interference;
	 * SUID, SGID and LSM creds get determined differently under ptrace.
	 */
	retval = mutex_lock_interruptible(&current->cred_exec_mutex);
	if (retval  < 0)
		goto out;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	retval = -EPERM;
repeat:
	/*
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 * Nasty, nasty.
	 *
	 * We want to hold both the task-lock and the
	 * tasklist_lock for writing at the same time.
	 * But that's against the rules (tasklist_lock
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 * is taken for reading by interrupts on other
	 * cpu's that may have task_lock).
	 */
	task_lock(task);
	if (!write_trylock_irqsave(&tasklist_lock, flags)) {
		task_unlock(task);
		do {
			cpu_relax();
		} while (!write_can_lock(&tasklist_lock));
		goto repeat;
	}

	if (!task->mm)
		goto bad;
	/* the same process cannot be attached many times */
	if (task->ptrace & PT_PTRACED)
		goto bad;
	retval = __ptrace_may_access(task, PTRACE_MODE_ATTACH);
	if (retval)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		goto bad;

	/* Go */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	task->ptrace |= PT_PTRACED;
	if (capable(CAP_SYS_PTRACE))
		task->ptrace |= PT_PTRACE_CAP;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	__ptrace_link(task, current);

	send_sig_info(SIGSTOP, SEND_SIG_FORCED, task);
bad:
	write_unlock_irqrestore(&tasklist_lock, flags);
	task_unlock(task);
	mutex_unlock(&current->cred_exec_mutex);
out:
	return retval;
}
