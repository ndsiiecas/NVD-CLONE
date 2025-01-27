static void *CVE_2009_0269_PATCHED_ecryptfs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
int origin_a, origin_aa[4];
	char *buf;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int len = PAGE_SIZE, rc;
	mm_segment_t old_fs;

	/* Released in ecryptfs_put_link(); only release here on error */
	buf = kmalloc(len, GFP_KERNEL);
	if (!buf) {
		rc = -ENOMEM;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		goto out;
	}
	old_fs = get_fs();
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	set_fs(get_ds());
	ecryptfs_printk(KERN_DEBUG, "Calling readlink w/ "
			"dentry->d_name.name = [%s]\n", dentry->d_name.name);
	rc = dentry->d_inode->i_op->readlink(dentry, (char __user *)buf, len);
	set_fs(old_fs);
	if (rc < 0)
		goto out_free;
	else
		buf[rc] = '\0';
	rc = 0;
	nd_set_link(nd, buf);
	goto out;
out_free:
	kfree(buf);
out:
	return ERR_PTR(rc);
}
