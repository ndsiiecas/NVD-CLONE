long CVE_2010_4256_PATCHED_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct pipe_inode_info *pipe;
	long ret;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	pipe = get_pipe_info(file);
	if (!pipe)
		return -EBADF;

	mutex_lock(&pipe->inode->i_mutex);

	switch (cmd) {
	case F_SETPIPE_SZ: {
		unsigned int size, nr_pages;

		size = round_pipe_size(arg);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		nr_pages = size >> PAGE_SHIFT;

		ret = -EINVAL;
		if (!nr_pages)
			goto out;

		if (!capable(CAP_SYS_RESOURCE) && size > pipe_max_size) {
			ret = -EPERM;
			goto out;
fclose(para_fp);
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
