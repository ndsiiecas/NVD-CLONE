static int
CVE_2009_3547_VULN_pipe_read_open(struct inode *inode, struct file *filp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	/* We could have perhaps used atomic_t, but this and friends
	   below are the only places.  So it doesn't seem worthwhile.  */
	mutex_lock(&inode->i_mutex);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	inode->i_pipe->readers++;
	mutex_unlock(&inode->i_mutex);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	return 0;
}
