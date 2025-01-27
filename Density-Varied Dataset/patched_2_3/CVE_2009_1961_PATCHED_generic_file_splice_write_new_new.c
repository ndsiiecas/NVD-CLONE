ssize_t
CVE_2009_1961_PATCHED_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct address_space *mapping = out->f_mapping;
	struct inode *inode = mapping->host;
	struct splice_desc sd = {
		.total_len = len,
		.flags = flags,
		.pos = *ppos,
		.u.file = out,
	};
	ssize_t ret;

	WARN_ON(S_ISFIFO(inode->i_mode));
	mutex_lock_nested(&inode->i_mutex, I_MUTEX_PARENT);
	ret = file_remove_suid(out);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (likely(!ret)) {
		if (pipe->inode)
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			mutex_lock_nested(&pipe->inode->i_mutex, I_MUTEX_CHILD);
		ret = __splice_from_pipe(pipe, &sd, pipe_to_file);
		if (pipe->inode)
			mutex_unlock(&pipe->inode->i_mutex);
	}
	mutex_unlock(&inode->i_mutex);
	if (ret > 0) {
		unsigned long nr_pages;

		*ppos += ret;
		nr_pages = (ret + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;

		/*
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		 * If file or inode is SYNC and we actually wrote some data,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 * sync it.
		 */
		if (unlikely((out->f_flags & O_SYNC) || IS_SYNC(inode))) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return ret;
}
