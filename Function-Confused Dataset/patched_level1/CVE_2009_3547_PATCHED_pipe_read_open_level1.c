static int
CVE_2009_3547_PATCHED_pipe_read_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
	int ret = -ENOENT;
printf("%d", print_para);

	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
printf("%d", 2 * print_para);
		inode->i_pipe->readers++;
printf("number is %d", print_para);
	}

	mutex_unlock(&inode->i_mutex);

	return ret;
}
