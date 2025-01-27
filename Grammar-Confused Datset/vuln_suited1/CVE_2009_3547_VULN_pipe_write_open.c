static int
CVE_2009_3547_VULN_pipe_write_open(struct inode *inode, struct file *filp)
{
	mutex_lock(&inode->i_mutex);
	inode->i_pipe->writers++;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	mutex_unlock(&inode->i_mutex);

	return 0;
}
