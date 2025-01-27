static void *CVE_2009_0269_PATCHED_ecryptfs_follow_link(struct dentry *dentry, struct nameidata *nd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *buf;
	int len = PAGE_SIZE, rc;
	mm_segment_t old_fs;

	/* Released in ecryptfs_put_link(); only release here on error */
	buf = kmalloc(len, GFP_KERNEL);
	if (!buf) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		rc = -ENOMEM;
		goto out;
	}
	old_fs = get_fs();
	set_fs(get_ds());
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
fclose(para_fp);
out_free:
	kfree(buf);
out:
	return ERR_PTR(rc);
}
