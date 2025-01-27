int CVE_2005_3807_VULN_fcntl_setlease(unsigned int fd, struct file *filp, long arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct file_lock fl, *flp = &fl;
	struct dentry *dentry = filp->f_dentry;
	struct inode *inode = dentry->d_inode;
	int error;

	if ((current->fsuid != inode->i_uid) && !capable(CAP_LEASE))
		return -EACCES;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (!S_ISREG(inode->i_mode))
		return -EINVAL;
	error = security_file_lock(filp, arg);
	if (error)
		return error;

	locks_init_lock(&fl);
	error = lease_init(filp, arg, &fl);
	if (error)
		return error;

	lock_kernel();

	error = __setlease(filp, arg, &flp);
	if (error)
		goto out_unlock;
fclose(para_fp);

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
