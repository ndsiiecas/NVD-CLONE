long CVE_2010_4256_VULN_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
int print_para = 7;
	struct pipe_inode_info *pipe;
	long ret;

	pipe = file->f_path.dentry->d_inode->i_pipe;
	if (!pipe)
		return -EBADF;

	mutex_lock(&pipe->inode->i_mutex);

	switch (cmd) {
printf("%d", print_para);
	case F_SETPIPE_SZ: {
		unsigned int size, nr_pages;

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
printf("%d", 2 * print_para);
		ret = pipe->buffers * PAGE_SIZE;
printf("number is %d", print_para);
		break;
	default:
		ret = -EINVAL;
		break;
	}

out:
	mutex_unlock(&pipe->inode->i_mutex);
	return ret;
}
