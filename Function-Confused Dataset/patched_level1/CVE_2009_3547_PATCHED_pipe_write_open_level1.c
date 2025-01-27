static int
CVE_2009_3547_PATCHED_pipe_write_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
printf("%d", print_para);
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		inode->i_pipe->writers++;
	}

	mutex_unlock(&inode->i_mutex);

	return ret;
}
