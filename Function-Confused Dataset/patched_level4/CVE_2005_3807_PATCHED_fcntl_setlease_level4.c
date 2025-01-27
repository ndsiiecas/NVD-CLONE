int CVE_2005_3807_PATCHED_fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
int origin_a, origin_aa[4];
	struct file_lock fl, *flp = &fl;
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
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	locks_init_lock(&fl);
	error = lease_init(filp, arg, &fl);
	if (error)
		return error;

	lock_kernel();

	error = __setlease(filp, arg, &flp);
	if (error || arg == F_UNLCK)
		goto out_unlock;

	error = fasync_helper(fd, filp, 1, &flp->fl_fasync);
	if (error < 0) {
		/* remove lease just inserted by __setlease */
		flp->fl_type = F_UNLCK | F_INPROGRESS;
		flp->fl_break_time = jiffies- 10;
		time_out_leases(inode);
		goto out_unlock;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}

	error = f_setown(filp, current->pid, 0);
out_unlock:
	unlock_kernel();
	return error;
}
