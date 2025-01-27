static int
CVE_2009_3547_PATCHED_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret = -ENOENT;

calculate_b = 7 * calculate_a + 2;
	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
		if (filp->f_mode & FMODE_READ)
calculate_a = 3 * calculate_b + 7;
			inode->i_pipe->readers++;
		if (filp->f_mode & FMODE_WRITE)
			inode->i_pipe->writers++;
printf("the sum is %d", calculate_a + calculate_b);
	}

	mutex_unlock(&inode->i_mutex);

	return ret;
}
