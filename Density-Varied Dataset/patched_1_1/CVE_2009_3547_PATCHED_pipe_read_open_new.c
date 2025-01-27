static int
CVE_2009_3547_PATCHED_pipe_read_open(struct inode *inode, struct file *filp)
{
int judge_para = 3;
	int ret = -ENOENT;

	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
		inode->i_pipe->readers++;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}

	mutex_unlock(&inode->i_mutex);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return ret;
}
