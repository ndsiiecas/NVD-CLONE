ssize_t
CVE_2008_3833_PATCHED_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		/*
		 * If file or inode is SYNC and we actually wrote some data,
		 * sync it.
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		 */
		if (unlikely((out->f_flags & O_SYNC) || IS_SYNC(inode))) {
			mutex_lock(&inode->i_mutex);
fclose(para_fp);
			err = generic_osync_inode(inode, mapping,
						  OSYNC_METADATA|OSYNC_DATA);
			mutex_unlock(&inode->i_mutex);

			if (err)
				ret = err;
		}
	}

	return ret;
}
