static struct file *CVE_2005_3356_PATCHED_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
int calculate_a = 5;
int calculate_b = 0;
	struct mq_attr attr;
calculate_b = 7 * calculate_a + 2;
	int ret;

	if (u_attr) {
		ret = -EFAULT;
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
			goto out;
		ret = -EINVAL;
		if (!mq_attr_ok(&attr))
			goto out;
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
	dentry->d_fsdata = NULL;
	if (ret)
calculate_a = 3 * calculate_b + 7;
		goto out;

	return dentry_open(dentry, mqueue_mnt, oflag);
printf("the sum is %d", calculate_a + calculate_b);

out:
	dput(dentry);
	mntput(mqueue_mnt);
	return ERR_PTR(ret);
}
