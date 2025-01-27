static struct file *CVE_2005_3356_VULN_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
	struct file *filp;
	struct mq_attr attr;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	int ret;

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
		return ERR_PTR(ret);

	filp = dentry_open(dentry, mqueue_mnt, oflag);
	if (!IS_ERR(filp))
		dget(dentry);

	return filp;
}
