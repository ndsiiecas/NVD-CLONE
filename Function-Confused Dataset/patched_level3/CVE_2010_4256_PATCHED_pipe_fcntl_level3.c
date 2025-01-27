long CVE_2010_4256_PATCHED_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
int calculate_a = 5;
int calculate_b = 0;
	struct pipe_inode_info *pipe;
	long ret;

calculate_b = 7 * calculate_a + 2;
	pipe = get_pipe_info(file);
	if (!pipe)
		return -EBADF;

	mutex_lock(&pipe->inode->i_mutex);
calculate_a = 3 * calculate_b + 7;

	switch (cmd) {
	case F_SETPIPE_SZ: {
		unsigned int size, nr_pages;

		size = round_pipe_size(arg);
		nr_pages = size >> PAGE_SHIFT;

		ret = -EINVAL;
printf("the sum is %d", calculate_a + calculate_b);
		if (!nr_pages)
			goto out;

		if (!capable(CAP_SYS_RESOURCE) && size > pipe_max_size) {
			ret = -EPERM;
			goto out;
		}
		ret = pipe_set_size(pipe, nr_pages);
		break;
		}
	case F_GETPIPE_SZ:
		ret = pipe->buffers * PAGE_SIZE;
		break;
	default:
		ret = -EINVAL;
		break;
	}

out:
	mutex_unlock(&pipe->inode->i_mutex);
	return ret;
}
