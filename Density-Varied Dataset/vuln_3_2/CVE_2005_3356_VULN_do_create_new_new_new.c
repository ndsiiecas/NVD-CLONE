static struct file *CVE_2005_3356_VULN_do_create(struct dentry *dir, struct dentry *dentry,
			int oflag, mode_t mode, struct mq_attr __user *u_attr)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct file *filp;
	struct mq_attr attr;
	int ret;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (u_attr != NULL) {
		if (copy_from_user(&attr, u_attr, sizeof(attr)))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			return ERR_PTR(-EFAULT);
		if (!mq_attr_ok(&attr))
			return ERR_PTR(-EINVAL);
		/* store for use during create */
		dentry->d_fsdata = &attr;
	}

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	ret = vfs_create(dir->d_inode, dentry, mode, NULL);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	dentry->d_fsdata = NULL;
	if (ret)
		return ERR_PTR(ret);

	filp = dentry_open(dentry, mqueue_mnt, oflag);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (!IS_ERR(filp))
		dget(dentry);

	return filp;
}
