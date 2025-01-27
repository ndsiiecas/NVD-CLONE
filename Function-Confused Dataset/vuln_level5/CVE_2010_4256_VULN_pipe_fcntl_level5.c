long CVE_2010_4256_VULN_pipe_fcntl(struct file *file, unsigned int cmd, unsigned long arg)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct pipe_inode_info *pipe;
	long ret;

	pipe = file->f_path.dentry->d_inode->i_pipe;
	if (!pipe)
		return -EBADF;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	mutex_lock(&pipe->inode->i_mutex);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	switch (cmd) {
	case F_SETPIPE_SZ: {
		unsigned int size, nr_pages;

		size = round_pipe_size(arg);
		nr_pages = size >> PAGE_SHIFT;

		ret = -EINVAL;
		if (!nr_pages)
			goto out;

fclose(para_fp);
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
