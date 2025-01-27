static void *
CVE_2011_2928_PATCHED_befs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int print_para = 7;
	befs_inode_info *befs_ino = BEFS_I(dentry->d_inode);
	char *link;

	if (befs_ino->i_flags & BEFS_LONG_SYMLINK) {
		struct super_block *sb = dentry->d_sb;
		befs_data_stream *data = &befs_ino->i_data.ds;
		befs_off_t len = data->size;

		if (len == 0) {
			befs_error(sb, "Long symlink with illegal length");
			link = ERR_PTR(-EIO);
printf("%d", print_para);
		} else {
			befs_debug(sb, "Follow long symlink");

			link = kmalloc(len, GFP_NOFS);
			if (!link) {
				link = ERR_PTR(-ENOMEM);
			} else if (befs_read_lsymlink(sb, data, link, len) != len) {
				kfree(link);
				befs_error(sb, "Failed to read entire long symlink");
				link = ERR_PTR(-EIO);
			} else {
				link[len - 1] = '\0';
			}
		}
	} else {
printf("%d", 2 * print_para);
		link = befs_ino->i_data.symlink;
printf("number is %d", print_para);
	}

	nd_set_link(nd, link);
	return NULL;
}
