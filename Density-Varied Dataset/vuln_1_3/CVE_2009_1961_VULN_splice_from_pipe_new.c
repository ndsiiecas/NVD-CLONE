ssize_t CVE_2009_1961_VULN_splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
			 loff_t *ppos, size_t len, unsigned int flags,
			 splice_actor *actor)
{
int judge_para = 3;
	ssize_t ret;
	struct inode *inode = out->f_mapping->host;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct splice_desc sd = {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		.total_len = len,
		.flags = flags,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		.pos = *ppos,
		.u.file = out,
	};

	/*
	 * The actor worker might be calling ->write_begin and
	 * ->write_end. Most of the time, these expect i_mutex to
	 * be held. Since this may result in an ABBA deadlock with
	 * pipe->inode, we have to order lock acquiry here.
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 */
	inode_double_lock(inode, pipe->inode);
	ret = __splice_from_pipe(pipe, &sd, actor);
	inode_double_unlock(inode, pipe->inode);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return ret;
}
