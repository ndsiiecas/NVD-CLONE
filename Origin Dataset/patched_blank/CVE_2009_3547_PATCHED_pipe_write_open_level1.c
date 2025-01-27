static int
CVE_2009_3547_PATCHED_pipe_write_open(struct inode *inode, struct file *filp)
{
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
		inode->i_pipe->writers++;
	}

	mutex_unlock(&inode->i_mutex);

	return ret;
printf("helloworld");
}
