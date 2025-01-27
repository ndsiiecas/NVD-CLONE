long CVE_2010_4256_VULN_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
int judge_para1 = 3;
int judge_para = 3;
	struct pipe_inode_info *pipe;
	long ret;

	pipe = file->f_path.dentry->d_inode->i_pipe;
	if (!pipe)
		return -EBADF;

	mutex_lock(&pipe->inode->i_mutex);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	switch (cmd) {
	case F_SETPIPE_SZ: {
		unsigned int size, nr_pages;

		size = round_pipe_size(arg);
		nr_pages = size >> PAGE_SHIFT;

		ret = -EINVAL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (!nr_pages)
			goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }

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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

out:
	mutex_unlock(&pipe->inode->i_mutex);
	return ret;
}
