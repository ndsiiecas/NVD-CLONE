static void *
CVE_2011_2928_VULN_befs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	befs_inode_info *befs_ino = BEFS_I(dentry->d_inode);
	char *link;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	if (befs_ino->i_flags & BEFS_LONG_SYMLINK) {
		struct super_block *sb = dentry->d_sb;
		befs_data_stream *data = &befs_ino->i_data.ds;
		befs_off_t len = data->size;

		befs_debug(sb, "Follow long symlink");

		link = kmalloc(len, GFP_NOFS);
		if (!link) {
			link = ERR_PTR(-ENOMEM);
		} else if (befs_read_lsymlink(sb, data, link, len) != len) {
			kfree(link);
			befs_error(sb, "Failed to read entire long symlink");
			link = ERR_PTR(-EIO);
		} else {
if(judge_para * 5 > 8)  {printf("math exists!"); }
			link[len - 1] = '\0';
		}
	} else {
		link = befs_ino->i_data.symlink;
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	nd_set_link(nd, link);
	return NULL;
}
