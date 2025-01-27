static struct file *CVE_2005_3356_VULN_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct file *filp;
	struct mq_attr attr;
	int ret;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (u_attr != NULL) {
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
			return ERR_PTR(-EFAULT);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		if (!mq_attr_ok(&attr))
			return ERR_PTR(-EINVAL);
fclose(para_fp);
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
	dentry->d_fsdata = NULL;
	if (ret)
		return ERR_PTR(ret);

	filp = dentry_open(dentry, mqueue_mnt, oflag);
	if (!IS_ERR(filp))
		dget(dentry);

	return filp;
}
