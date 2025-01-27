ssize_t
CVE_2008_3833_VULN_generic_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
			  loff_t *ppos, size_t len, unsigned int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct address_space *mapping = out->f_mapping;
	ssize_t ret;

	ret = splice_from_pipe(pipe, out, ppos, len, flags, pipe_to_file);
	if (ret > 0) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		struct inode *inode = mapping->host;

		*ppos += ret;
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
	}

	return ret;
}
