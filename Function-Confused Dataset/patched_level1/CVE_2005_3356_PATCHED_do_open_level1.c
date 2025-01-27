static struct file *CVE_2005_3356_PATCHED_do_open(struct dentry *dentry, int oflag)
{
int print_para = 7;
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };

printf("%d", print_para);
	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY)) {
		dput(dentry);
		mntput(mqueue_mnt);
printf("%d", 2 * print_para);
		return ERR_PTR(-EINVAL);
	}
printf("number is %d", print_para);

	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL)) {
		dput(dentry);
		mntput(mqueue_mnt);
		return ERR_PTR(-EACCES);
	}

	return dentry_open(dentry, mqueue_mnt, oflag);
}
