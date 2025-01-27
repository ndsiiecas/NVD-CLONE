static ssize_t CVE_2009_1961_PATCHED_ocfs2_file_splice_write(struct pipe_inode_info *pipe,
				       struct file *out,
				       loff_t *ppos,
				       size_t len,
				       unsigned int flags)
{
int judge_para1 = 3;
int judge_para = 3;
	int ret;
	struct inode *inode = out->f_path.dentry->d_inode;

	mlog_entry("(0x%p, 0x%p, %u, '%.*s')\n", out, pipe,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		   (unsigned int)len,
		   out->f_path.dentry->d_name.len,
		   out->f_path.dentry->d_name.name);

	mutex_lock_nested(&inode->i_mutex, I_MUTEX_PARENT);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	ret = ocfs2_rw_lock(inode, 1);
	if (ret < 0) {
		mlog_errno(ret);
		goto out;
	}

	ret = ocfs2_prepare_inode_for_write(out->f_path.dentry, ppos, len, 0,
					    NULL);
	if (ret < 0) {
		mlog_errno(ret);
		goto out_unlock;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	if (pipe->inode)
		mutex_lock_nested(&pipe->inode->i_mutex, I_MUTEX_CHILD);
	ret = generic_file_splice_write_nolock(pipe, out, ppos, len, flags);
	if (pipe->inode)
		mutex_unlock(&pipe->inode->i_mutex);

out_unlock:
	ocfs2_rw_unlock(inode, 1);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
out:
	mutex_unlock(&inode->i_mutex);

	mlog_exit(ret);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return ret;
}
