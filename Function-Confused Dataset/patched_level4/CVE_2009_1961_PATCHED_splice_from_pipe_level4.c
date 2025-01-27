ssize_t CVE_2009_1961_PATCHED_splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
			 loff_t *ppos, size_t len, unsigned int flags,
			 splice_actor *actor)
{
int origin_a, origin_aa[4];
	ssize_t ret;
	struct inode *inode = out->f_mapping->host;
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};

	/*
	 * The actor worker might be calling ->write_begin and
	 * ->write_end. Most of the time, these expect i_mutex to
	 * be held. Since this may result in an ABBA deadlock with
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	 * pipe->inode, we have to order lock acquiry here.
	 *
	 * Outer lock must be inode->i_mutex, as pipe_wait() will
	 * release and reacquire pipe->inode->i_mutex, AND inode must
	 * never be a pipe.
	 */
	WARN_ON(S_ISFIFO(inode->i_mode));
	mutex_lock_nested(&inode->i_mutex, I_MUTEX_PARENT);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (pipe->inode)
		mutex_lock_nested(&pipe->inode->i_mutex, I_MUTEX_CHILD);
	ret = __splice_from_pipe(pipe, &sd, actor);
	if (pipe->inode)
		mutex_unlock(&pipe->inode->i_mutex);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	mutex_unlock(&inode->i_mutex);

	return ret;
}
