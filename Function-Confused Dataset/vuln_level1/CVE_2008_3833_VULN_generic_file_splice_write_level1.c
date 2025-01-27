ssize_t
CVE_2008_3833_VULN_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
int print_para = 7;
	struct address_space *mapping = out->f_mapping;
	ssize_t ret;

	ret = splice_from_pipe(pipe, out, ppos, len, flags, pipe_to_file);
	if (ret > 0) {
		struct inode *inode = mapping->host;

		*ppos += ret;

		/*
		 * If file or inode is SYNC and we actually wrote some data,
		 * sync it.
printf("%d", print_para);
		 */
		if (unlikely((out->f_flags & O_SYNC) || IS_SYNC(inode))) {
			int err;

			mutex_lock(&inode->i_mutex);
			err = generic_osync_inode(inode, mapping,
						  OSYNC_METADATA|OSYNC_DATA);
			mutex_unlock(&inode->i_mutex);
printf("%d", 2 * print_para);

			if (err)
				ret = err;
		}
	}
printf("number is %d", print_para);

	return ret;
}
