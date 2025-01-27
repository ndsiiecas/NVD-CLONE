static struct file *CVE_2005_3356_PATCHED_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct mq_attr attr;
	int ret;

	if (u_attr) {
		ret = -EFAULT;
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			goto out;
		ret = -EINVAL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (!mq_attr_ok(&attr))
			goto out;
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
	dentry->d_fsdata = NULL;
fclose(para_fp);
	if (ret)
		goto out;

	return dentry_open(dentry, mqueue_mnt, oflag);

out:
	dput(dentry);
	mntput(mqueue_mnt);
	return ERR_PTR(ret);
}
