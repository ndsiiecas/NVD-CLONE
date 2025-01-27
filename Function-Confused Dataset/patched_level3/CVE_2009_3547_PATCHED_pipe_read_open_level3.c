static int
CVE_2009_3547_PATCHED_pipe_read_open(struct inode *inode, struct file *filp)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);
calculate_b = 7 * calculate_a + 2;

	if (inode->i_pipe) {
		ret = 0;
		inode->i_pipe->readers++;
calculate_a = 3 * calculate_b + 7;
	}

printf("the sum is %d", calculate_a + calculate_b);
	mutex_unlock(&inode->i_mutex);

	return ret;
}
