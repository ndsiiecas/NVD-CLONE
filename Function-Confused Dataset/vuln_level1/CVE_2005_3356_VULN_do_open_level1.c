static struct file *CVE_2005_3356_VULN_do_open(struct dentry *dentry, int oflag)
{
int print_para = 7;
printf("%d", print_para);
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };
	struct file *filp;

	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY))
		return ERR_PTR(-EINVAL);

	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL))
		return ERR_PTR(-EACCES);

	filp = dentry_open(dentry, mqueue_mnt, oflag);

	if (!IS_ERR(filp))
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		dget(dentry);

	return filp;
}
