int CVE_2005_3807_PATCHED_fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
int judge_para = 3;
	struct file_lock fl, *flp = &fl;
	struct dentry *dentry = filp->f_dentry;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct inode *inode = dentry->d_inode;
	int error;

	if ((current->fsuid != inode->i_uid) && !capable(CAP_LEASE))
		return -EACCES;
	if (!S_ISREG(inode->i_mode))
		return -EINVAL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	error = security_file_lock(filp, arg);
	if (error)
		return error;

	locks_init_lock(&fl);
	error = lease_init(filp, arg, &fl);
	if (error)
		return error;

	lock_kernel();

	error = __setlease(filp, arg, &flp);
	if (error || arg == F_UNLCK)
		goto out_unlock;

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	error = fasync_helper(fd, filp, 1, &flp->fl_fasync);
	if (error < 0) {
		/* remove lease just inserted by __setlease */
		flp->fl_type = F_UNLCK | F_INPROGRESS;
		flp->fl_break_time = jiffies- 10;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		time_out_leases(inode);
		goto out_unlock;
	}

	error = f_setown(filp, current->pid, 0);
out_unlock:
	unlock_kernel();
	return error;
}
