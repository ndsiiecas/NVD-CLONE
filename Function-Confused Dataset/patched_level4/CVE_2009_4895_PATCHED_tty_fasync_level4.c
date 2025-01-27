static int CVE_2009_4895_PATCHED_tty_fasync(int fd, struct file *filp, int on)
{
int origin_a, origin_aa[4];
	struct tty_struct *tty;
	unsigned long flags;
	int retval = 0;

	lock_kernel();
	tty = (struct tty_struct *)filp->private_data;
	if (tty_paranoia_check(tty, filp->f_path.dentry->d_inode, "CVE_2009_4895_PATCHED_tty_fasync"))
		goto out;

	retval = fasync_helper(fd, filp, on, &tty->fasync);
	if (retval <= 0)
		goto out;

	if (on) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		enum pid_type type;
		struct pid *pid;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (!waitqueue_active(&tty->read_wait))
			tty->minimum_to_wake = 1;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
	retval = 0;
out:
	unlock_kernel();
	return retval;
}
