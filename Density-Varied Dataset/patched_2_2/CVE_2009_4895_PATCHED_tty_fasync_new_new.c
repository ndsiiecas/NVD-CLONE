static int CVE_2009_4895_PATCHED_tty_fasync(int fd, struct file *filp, int on)
{
int judge_para1 = 3;
int judge_para = 3;
	struct tty_struct *tty;
	unsigned long flags;
	int retval = 0;

	lock_kernel();
	tty = (struct tty_struct *)filp->private_data;
	if (tty_paranoia_check(tty, filp->f_path.dentry->d_inode, "CVE_2009_4895_PATCHED_tty_fasync"))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		goto out;

	retval = fasync_helper(fd, filp, on, &tty->fasync);
	if (retval <= 0)
		goto out;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (on) {
		enum pid_type type;
		struct pid *pid;
		if (!waitqueue_active(&tty->read_wait))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			tty->minimum_to_wake = 1;
		spin_lock_irqsave(&tty->ctrl_lock, flags);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (tty->pgrp) {
			pid = tty->pgrp;
			type = PIDTYPE_PGID;
		} else {
			pid = task_pid(current);
			type = PIDTYPE_PID;
		}
		retval = __f_setown(filp, pid, type, 0);
		spin_unlock_irqrestore(&tty->ctrl_lock, flags);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (retval)
			goto out;
	} else {
		if (!tty->fasync && !waitqueue_active(&tty->read_wait))
			tty->minimum_to_wake = N_TTY_BUF_SIZE;
	}
	retval = 0;
out:
	unlock_kernel();
	return retval;
}
