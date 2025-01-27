ssize_t
CVE_2008_3833_PATCHED_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	struct address_space *mapping = out->f_mapping;
	struct inode *inode = mapping->host;
	ssize_t ret;
	int err;

	err = should_remove_suid(out->f_dentry);
	if (unlikely(err)) {
		mutex_lock(&inode->i_mutex);
		err = __remove_suid(out->f_dentry, err);
		mutex_unlock(&inode->i_mutex);
		if (err)
			return err;
	}

	ret = splice_from_pipe(pipe, out, ppos, len, flags, pipe_to_file);
	if (ret > 0) {
		*ppos += ret;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		/*
		 * If file or inode is SYNC and we actually wrote some data,
		 * sync it.
		 */
		if (unlikely((out->f_flags & O_SYNC) || IS_SYNC(inode))) {
			mutex_lock(&inode->i_mutex);
			err = generic_osync_inode(inode, mapping,
						  OSYNC_METADATA|OSYNC_DATA);
			mutex_unlock(&inode->i_mutex);

			if (err)
				ret = err;
		}
	}

	return ret;
}
