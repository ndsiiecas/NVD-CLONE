static int CVE_2009_4895_PATCHED_tty_fasync(int fd, struct file *filp, int on)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct tty_struct *tty;
	unsigned long flags;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int retval = 0;

	lock_kernel();
	tty = (struct tty_struct *)filp->private_data;
	if (tty_paranoia_check(tty, filp->f_path.dentry->d_inode, "CVE_2009_4895_PATCHED_tty_fasync"))
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
	retval = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
out:
fclose(para_fp);
	unlock_kernel();
	return retval;
}
