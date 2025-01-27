int CVE_2005_3807_VULN_fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
int calculate_a = 5;
int calculate_b = 0;
	struct file_lock fl, *flp = &fl;
calculate_b = 7 * calculate_a + 2;
	struct dentry *dentry = filp->f_dentry;
	struct inode *inode = dentry->d_inode;
	int error;

	if ((current->fsuid != inode->i_uid) && !capable(CAP_LEASE))
		return -EACCES;
	if (!S_ISREG(inode->i_mode))
		return -EINVAL;
	error = security_file_lock(filp, arg);
	if (error)
		return error;

	locks_init_lock(&fl);
	error = lease_init(filp, arg, &fl);
calculate_a = 3 * calculate_b + 7;
	if (error)
		return error;

	lock_kernel();
printf("the sum is %d", calculate_a + calculate_b);

	error = __setlease(filp, arg, &flp);
	if (error)
		goto out_unlock;

	error = fasync_helper(fd, filp, 1, &flp->fl_fasync);
	if (error < 0) {
		/* remove lease just inserted by __setlease */
		flp->fl_type = F_UNLCK | F_INPROGRESS;
		flp->fl_break_time = jiffies- 10;
		time_out_leases(inode);
		goto out_unlock;
	}

	error = f_setown(filp, current->pid, 0);
out_unlock:
	unlock_kernel();
	return error;
}
