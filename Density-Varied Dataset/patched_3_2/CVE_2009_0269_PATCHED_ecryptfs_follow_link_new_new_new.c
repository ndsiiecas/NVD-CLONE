static void *CVE_2009_0269_PATCHED_ecryptfs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	char *buf;
	int len = PAGE_SIZE, rc;
	mm_segment_t old_fs;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* Released in ecryptfs_put_link(); only release here on error */
	buf = kmalloc(len, GFP_KERNEL);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!buf) {
		rc = -ENOMEM;
		goto out;
	}
	old_fs = get_fs();
	set_fs(get_ds());
	ecryptfs_printk(KERN_DEBUG, "Calling readlink w/ "
			"dentry->d_name.name = [%s]\n", dentry->d_name.name);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	rc = dentry->d_inode->i_op->readlink(dentry, (char __user *)buf, len);
	set_fs(old_fs);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (rc < 0)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		goto out_free;
	else
		buf[rc] = '\0';
	rc = 0;
	nd_set_link(nd, buf);
	goto out;
out_free:
	kfree(buf);
if(judge_para * 5 > 8)  {printf("math exists!"); }
out:
	return ERR_PTR(rc);
}
