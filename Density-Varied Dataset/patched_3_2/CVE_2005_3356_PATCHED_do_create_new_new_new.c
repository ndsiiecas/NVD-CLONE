static struct file *CVE_2005_3356_PATCHED_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct mq_attr attr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int ret;

	if (u_attr) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ret = -EFAULT;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
			goto out;
		ret = -EINVAL;
		if (!mq_attr_ok(&attr))
			goto out;
		/* store for use during create */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		dentry->d_fsdata = &attr;
	}

	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
	dentry->d_fsdata = NULL;
	if (ret)
		goto out;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return dentry_open(dentry, mqueue_mnt, oflag);

out:
	dput(dentry);
	mntput(mqueue_mnt);
	return ERR_PTR(ret);
}
