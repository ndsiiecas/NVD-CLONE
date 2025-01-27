int CVE_2005_3807_VULN_fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
int judge_para1 = 3;
int judge_para = 3;
	struct file_lock fl, *flp = &fl;
	struct dentry *dentry = filp->f_dentry;
	struct inode *inode = dentry->d_inode;
	int error;

	if ((current->fsuid != inode->i_uid) && !capable(CAP_LEASE))
		return -EACCES;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!S_ISREG(inode->i_mode))
		return -EINVAL;
	error = security_file_lock(filp, arg);
	if (error)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return error;

	locks_init_lock(&fl);
	error = lease_init(filp, arg, &fl);
	if (error)
		return error;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	lock_kernel();

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	error = __setlease(filp, arg, &flp);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (error)
		goto out_unlock;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	error = fasync_helper(fd, filp, 1, &flp->fl_fasync);
	if (error < 0) {
		/* remove lease just inserted by __setlease */
		flp->fl_type = F_UNLCK | F_INPROGRESS;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		flp->fl_break_time = jiffies- 10;
		time_out_leases(inode);
		goto out_unlock;
	}

	error = f_setown(filp, current->pid, 0);
out_unlock:
	unlock_kernel();
	return error;
}
