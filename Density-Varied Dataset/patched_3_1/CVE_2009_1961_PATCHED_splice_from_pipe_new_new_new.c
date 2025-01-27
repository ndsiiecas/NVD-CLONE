ssize_t CVE_2009_1961_PATCHED_splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
			 loff_t *ppos, size_t len, unsigned int flags,
			 splice_actor *actor)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	ssize_t ret;
	struct inode *inode = out->f_mapping->host;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	};

	/*
	 * The actor worker might be calling ->write_begin and
	 * ->write_end. Most of the time, these expect i_mutex to
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	 * be held. Since this may result in an ABBA deadlock with
	 * pipe->inode, we have to order lock acquiry here.
	 *
	 * Outer lock must be inode->i_mutex, as pipe_wait() will
	 * release and reacquire pipe->inode->i_mutex, AND inode must
	 * never be a pipe.
	 */
	WARN_ON(S_ISFIFO(inode->i_mode));
	mutex_lock_nested(&inode->i_mutex, I_MUTEX_PARENT);
	if (pipe->inode)
		mutex_lock_nested(&pipe->inode->i_mutex, I_MUTEX_CHILD);
	ret = __splice_from_pipe(pipe, &sd, actor);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (pipe->inode)
		mutex_unlock(&pipe->inode->i_mutex);
	mutex_unlock(&inode->i_mutex);

	return ret;
}
