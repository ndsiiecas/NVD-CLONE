static int
CVE_2009_3547_VULN_pipe_write_open(struct inode *inode, struct file *filp)
{
int judge_para = 3;
	mutex_lock(&inode->i_mutex);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	inode->i_pipe->writers++;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	mutex_unlock(&inode->i_mutex);

	return 0;
}
