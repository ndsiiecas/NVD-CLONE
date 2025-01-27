static int
CVE_2009_3547_PATCHED_pipe_write_open(struct inode *inode, struct file *filp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	int ret = -ENOENT;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	mutex_lock(&inode->i_mutex);

	if (inode->i_pipe) {
		ret = 0;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		inode->i_pipe->writers++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}

	mutex_unlock(&inode->i_mutex);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return ret;
}
