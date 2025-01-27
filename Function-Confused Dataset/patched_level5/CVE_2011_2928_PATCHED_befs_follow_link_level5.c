static void *
CVE_2011_2928_PATCHED_befs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	befs_inode_info *befs_ino = BEFS_I(dentry->d_inode);
	char *link;

	if (befs_ino->i_flags & BEFS_LONG_SYMLINK) {
		struct super_block *sb = dentry->d_sb;
		befs_data_stream *data = &befs_ino->i_data.ds;
		befs_off_t len = data->size;

		if (len == 0) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			befs_error(sb, "Long symlink with illegal length");
			link = ERR_PTR(-EIO);
		} else {
			befs_debug(sb, "Follow long symlink");

			link = kmalloc(len, GFP_NOFS);
			if (!link) {
				link = ERR_PTR(-ENOMEM);
			} else if (befs_read_lsymlink(sb, data, link, len) != len) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				kfree(link);
				befs_error(sb, "Failed to read entire long symlink");
				link = ERR_PTR(-EIO);
			} else {
				link[len - 1] = '\0';
			}
		}
fclose(para_fp);
	} else {
		link = befs_ino->i_data.symlink;
	}

	nd_set_link(nd, link);
	return NULL;
}
