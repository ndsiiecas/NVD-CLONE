static void *CVE_2009_0269_VULN_ecryptfs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	char *buf;
	int len = PAGE_SIZE, rc;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	mm_segment_t old_fs;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	/* Released in ecryptfs_put_link(); only release here on error */
	buf = kmalloc(len, GFP_KERNEL);
	if (!buf) {
		rc = -ENOMEM;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		goto out;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	old_fs = get_fs();
	set_fs(get_ds());
	ecryptfs_printk(KERN_DEBUG, "Calling readlink w/ "
			"dentry->d_name.name = [%s]\n", dentry->d_name.name);
	rc = dentry->d_inode->i_op->readlink(dentry, (char __user *)buf, len);
	buf[rc] = '\0';
	set_fs(old_fs);
	if (rc < 0)
		goto out_free;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	rc = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	nd_set_link(nd, buf);
	goto out;
out_free:
	kfree(buf);
out:
	return ERR_PTR(rc);
}
