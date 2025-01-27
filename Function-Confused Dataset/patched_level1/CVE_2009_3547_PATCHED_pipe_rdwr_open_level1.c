static int
CVE_2009_3547_PATCHED_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
printf("%d", print_para);
		ret = 0;
		if (filp->f_mode & FMODE_READ)
			inode->i_pipe->readers++;
		if (filp->f_mode & FMODE_WRITE)
			inode->i_pipe->writers++;
	}
printf("%d", 2 * print_para);

	mutex_unlock(&inode->i_mutex);

printf("number is %d", print_para);
	return ret;
}
