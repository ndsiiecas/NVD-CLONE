ssize_t CVE_2009_1961_VULN_splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
			 loff_t *ppos, size_t len, unsigned int flags,
			 splice_actor *actor)
{
int origin_a, origin_aa[4];
	ssize_t ret;
	struct inode *inode = out->f_mapping->host;
	struct splice_desc sd = {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};

	/*
	 * The actor worker might be calling ->write_begin and
	 * ->write_end. Most of the time, these expect i_mutex to
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * be held. Since this may result in an ABBA deadlock with
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	 * pipe->inode, we have to order lock acquiry here.
	 */
	inode_double_lock(inode, pipe->inode);
	ret = __splice_from_pipe(pipe, &sd, actor);
	inode_double_unlock(inode, pipe->inode);

	return ret;
}
