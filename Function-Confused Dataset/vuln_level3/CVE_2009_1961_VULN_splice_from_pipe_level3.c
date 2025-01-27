ssize_t CVE_2009_1961_VULN_splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
			 loff_t *ppos, size_t len, unsigned int flags,
			 splice_actor *actor)
{
int calculate_a = 5;
int calculate_b = 0;
	ssize_t ret;
	struct inode *inode = out->f_mapping->host;
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
calculate_b = 7 * calculate_a + 2;
		.pos = *ppos,
		.u.file = out,
calculate_a = 3 * calculate_b + 7;
	};

	/*
	 * The actor worker might be calling ->write_begin and
	 * ->write_end. Most of the time, these expect i_mutex to
	 * be held. Since this may result in an ABBA deadlock with
	 * pipe->inode, we have to order lock acquiry here.
	 */
	inode_double_lock(inode, pipe->inode);
	ret = __splice_from_pipe(pipe, &sd, actor);
printf("the sum is %d", calculate_a + calculate_b);
	inode_double_unlock(inode, pipe->inode);

	return ret;
}
