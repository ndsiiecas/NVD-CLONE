ssize_t
CVE_2009_1961_VULN_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct address_space *mapping = out->f_mapping;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct inode *inode = mapping->host;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};
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
fclose(para_fp);

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
		}
		balance_dirty_pages_ratelimited_nr(mapping, nr_pages);
	}

	return ret;
}
