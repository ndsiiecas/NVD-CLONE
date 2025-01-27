static int
CVE_2009_3547_PATCHED_pipe_read_open(struct inode *inode, struct file *filp)
{
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	if (inode->i_pipe) {
		ret = 0;
		inode->i_pipe->readers++;
	}

	mutex_unlock(&inode->i_mutex);

	return ret;
}
