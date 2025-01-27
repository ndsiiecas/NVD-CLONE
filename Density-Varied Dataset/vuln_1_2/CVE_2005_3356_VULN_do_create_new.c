static struct file *CVE_2005_3356_VULN_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
int judge_para = 3;
	struct file *filp;
	struct mq_attr attr;
	int ret;

	if (u_attr != NULL) {
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			return ERR_PTR(-EFAULT);
		if (!mq_attr_ok(&attr))
			return ERR_PTR(-EINVAL);
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	dentry->d_fsdata = NULL;
	if (ret)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return ERR_PTR(ret);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	filp = dentry_open(dentry, mqueue_mnt, oflag);
	if (!IS_ERR(filp))
		dget(dentry);

	return filp;
}
