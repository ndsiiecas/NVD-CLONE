static ssize_t CVE_2009_1961_VULN_ocfs2_file_splice_write(struct pipe_inode_info *pipe,
				       struct file *out,
				       loff_t *ppos,
				       size_t len,
				       unsigned int flags)
{
int origin_a, origin_aa[4];
	int ret;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct inode *inode = out->f_path.dentry->d_inode;

	mlog_entry("(0x%p, 0x%p, %u, '%.*s')\n", out, pipe,
		   (unsigned int)len,
		   out->f_path.dentry->d_name.len,
		   out->f_path.dentry->d_name.name);

	inode_double_lock(inode, pipe->inode);

	ret = ocfs2_rw_lock(inode, 1);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (ret < 0) {
		mlog_errno(ret);
		goto out;
	}

	ret = ocfs2_prepare_inode_for_write(out->f_path.dentry, ppos, len, 0,
					    NULL);
	if (ret < 0) {
		mlog_errno(ret);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		goto out_unlock;
	}

	ret = generic_file_splice_write_nolock(pipe, out, ppos, len, flags);

out_unlock:
	ocfs2_rw_unlock(inode, 1);
out:
	inode_double_unlock(inode, pipe->inode);

	mlog_exit(ret);
	return ret;
}
