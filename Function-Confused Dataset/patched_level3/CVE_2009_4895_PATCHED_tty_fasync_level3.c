static int CVE_2009_4895_PATCHED_tty_fasync(int fd, struct file *filp, int on)
{
int calculate_a = 5;
int calculate_b = 0;
	struct tty_struct *tty;
	unsigned long flags;
	int retval = 0;

	lock_kernel();
	tty = (struct tty_struct *)filp->private_data;
	if (tty_paranoia_check(tty, filp->f_path.dentry->d_inode, "CVE_2009_4895_PATCHED_tty_fasync"))
calculate_b = 7 * calculate_a + 2;
		goto out;

	retval = fasync_helper(fd, filp, on, &tty->fasync);
	if (retval <= 0)
		goto out;

	if (on) {
		enum pid_type type;
		struct pid *pid;
		if (!waitqueue_active(&tty->read_wait))
			tty->minimum_to_wake = 1;
		spin_lock_irqsave(&tty->ctrl_lock, flags);
		if (tty->pgrp) {
			pid = tty->pgrp;
			type = PIDTYPE_PGID;
		} else {
			pid = task_pid(current);
			type = PIDTYPE_PID;
		}
		retval = __f_setown(filp, pid, type, 0);
		spin_unlock_irqrestore(&tty->ctrl_lock, flags);
		if (retval)
			goto out;
	} else {
		if (!tty->fasync && !waitqueue_active(&tty->read_wait))
			tty->minimum_to_wake = N_TTY_BUF_SIZE;
	}
calculate_a = 3 * calculate_b + 7;
	retval = 0;
out:
printf("the sum is %d", calculate_a + calculate_b);
	unlock_kernel();
	return retval;
}
