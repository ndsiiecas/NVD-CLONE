static int
CVE_2009_3547_VULN_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	mutex_lock(&inode->i_mutex);
calculate_a = 3 * calculate_b + 7;
	if (filp->f_mode & FMODE_READ)
		inode->i_pipe->readers++;
printf("the sum is %d", calculate_a + calculate_b);
	if (filp->f_mode & FMODE_WRITE)
		inode->i_pipe->writers++;
	mutex_unlock(&inode->i_mutex);

	return 0;
}
