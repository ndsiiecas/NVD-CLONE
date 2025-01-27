static void *
CVE_2011_2928_PATCHED_befs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int origin_a, origin_aa[4];
	befs_inode_info *befs_ino = BEFS_I(dentry->d_inode);
	char *link;

	if (befs_ino->i_flags & BEFS_LONG_SYMLINK) {
		struct super_block *sb = dentry->d_sb;
		befs_data_stream *data = &befs_ino->i_data.ds;
		befs_off_t len = data->size;

		if (len == 0) {
			befs_error(sb, "Long symlink with illegal length");
			link = ERR_PTR(-EIO);
		} else {
			befs_debug(sb, "Follow long symlink");

			link = kmalloc(len, GFP_NOFS);
			if (!link) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
				link = ERR_PTR(-ENOMEM);
			} else if (befs_read_lsymlink(sb, data, link, len) != len) {
				kfree(link);
				befs_error(sb, "Failed to read entire long symlink");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
				link = ERR_PTR(-EIO);
			} else {
				link[len - 1] = '\0';
			}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		}
	} else {
		link = befs_ino->i_data.symlink;
	}

	nd_set_link(nd, link);
	return NULL;
}
