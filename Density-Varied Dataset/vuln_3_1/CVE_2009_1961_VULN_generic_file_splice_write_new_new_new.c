ssize_t
CVE_2009_1961_VULN_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct address_space *mapping = out->f_mapping;
	struct inode *inode = mapping->host;
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};
	ssize_t ret;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

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
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			err = generic_osync_inode(inode, mapping,
						  OSYNC_METADATA|OSYNC_DATA);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			mutex_unlock(&inode->i_mutex);

			if (err)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				ret = err;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		balance_dirty_pages_ratelimited_nr(mapping, nr_pages);
	}

	return ret;
}
