static int
CVE_2009_3547_VULN_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	mutex_lock(&inode->i_mutex);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (filp->f_mode & FMODE_READ)
if(judge_para * 5 > 8)  {printf("math exists!"); }
		inode->i_pipe->readers++;
	if (filp->f_mode & FMODE_WRITE)
		inode->i_pipe->writers++;
	mutex_unlock(&inode->i_mutex);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	return 0;
}
