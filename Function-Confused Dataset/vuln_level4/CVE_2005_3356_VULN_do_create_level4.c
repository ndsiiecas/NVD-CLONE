static struct file *CVE_2005_3356_VULN_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
int origin_a, origin_aa[4];
	struct file *filp;
	struct mq_attr attr;
	int ret;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (u_attr != NULL) {
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
			return ERR_PTR(-EFAULT);
		if (!mq_attr_ok(&attr))
			return ERR_PTR(-EINVAL);
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
	dentry->d_fsdata = NULL;
	if (ret)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return ERR_PTR(ret);

	filp = dentry_open(dentry, mqueue_mnt, oflag);
	if (!IS_ERR(filp))
		dget(dentry);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return filp;
}
