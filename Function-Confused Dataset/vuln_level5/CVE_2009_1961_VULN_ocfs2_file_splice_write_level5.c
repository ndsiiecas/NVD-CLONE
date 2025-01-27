static ssize_t CVE_2009_1961_VULN_ocfs2_file_splice_write(struct pipe_inode_info *pipe,
				       struct file *out,
				       loff_t *ppos,
				       size_t len,
				       unsigned int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct inode *inode = out->f_path.dentry->d_inode;

	mlog_entry("(0x%p, 0x%p, %u, '%.*s')\n", out, pipe,
		   (unsigned int)len,
		   out->f_path.dentry->d_name.len,
		   out->f_path.dentry->d_name.name);

	inode_double_lock(inode, pipe->inode);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

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
	}

	ret = generic_file_splice_write_nolock(pipe, out, ppos, len, flags);
fclose(para_fp);

out_unlock:
	ocfs2_rw_unlock(inode, 1);
out:
	inode_double_unlock(inode, pipe->inode);

	mlog_exit(ret);
	return ret;
}
