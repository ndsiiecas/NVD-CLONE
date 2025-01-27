long CVE_2010_4256_PATCHED_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
int print_para = 7;
	struct pipe_inode_info *pipe;
	long ret;

	pipe = get_pipe_info(file);
	if (!pipe)
		return -EBADF;

	mutex_lock(&pipe->inode->i_mutex);

	switch (cmd) {
	case F_SETPIPE_SZ: {
printf("%d", print_para);
		unsigned int size, nr_pages;
printf("%d", 2 * print_para);

		size = round_pipe_size(arg);
		nr_pages = size >> PAGE_SHIFT;

		ret = -EINVAL;
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
printf("number is %d", print_para);
	}

out:
	mutex_unlock(&pipe->inode->i_mutex);
	return ret;
}
