static struct file *CVE_2005_3356_VULN_do_open(struct dentry *dentry, int oflag)
{
int calculate_a = 5;
int calculate_b = 0;
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };
calculate_b = 7 * calculate_a + 2;
	struct file *filp;

	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY))
calculate_a = 3 * calculate_b + 7;
		return ERR_PTR(-EINVAL);

	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL))
		return ERR_PTR(-EACCES);

	filp = dentry_open(dentry, mqueue_mnt, oflag);

printf("the sum is %d", calculate_a + calculate_b);
	if (!IS_ERR(filp))
		dget(dentry);

	return filp;
}
