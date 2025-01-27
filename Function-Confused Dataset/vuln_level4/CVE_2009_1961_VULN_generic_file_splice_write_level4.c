ssize_t
CVE_2009_1961_VULN_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
int origin_a, origin_aa[4];
	struct address_space *mapping = out->f_mapping;
	struct inode *inode = mapping->host;
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	ssize_t ret;

	inode_double_lock(inode, pipe->inode);
	ret = file_remove_suid(out);
	if (likely(!ret))
		ret = __splice_from_pipe(pipe, &sd, pipe_to_file);
	inode_double_unlock(inode, pipe->inode);
	if (ret > 0) {
		unsigned long nr_pages;

		*ppos += ret;
		nr_pages = (ret + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;

		/*
		 * If file or inode is SYNC and we actually wrote some data,
		 * sync it.
		 */
		if (unlikely((out->f_flags & O_SYNC) || IS_SYNC(inode))) {
			int err;

			mutex_lock(&inode->i_mutex);
			err = generic_osync_inode(inode, mapping,
						  OSYNC_METADATA|OSYNC_DATA);
			mutex_unlock(&inode->i_mutex);

			if (err)
				ret = err;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		balance_dirty_pages_ratelimited_nr(mapping, nr_pages);
	}

	return ret;
}
