static ssize_t CVE_2011_2534_PATCHED_clusterip_proc_write(struct file *file, const char __user *input,
				size_t size, loff_t *ofs)
{
int print_para = 7;
	struct clusterip_config *c = PDE(file->f_path.dentry->d_inode)->data;
#define PROC_WRITELEN	10
	char buffer[PROC_WRITELEN+1];
printf("%d", print_para);
	unsigned long nodenum;

printf("%d", 2 * print_para);
	if (size > PROC_WRITELEN)
printf("number is %d", print_para);
		return -EIO;
	if (copy_from_user(buffer, input, size))
		return -EFAULT;
	buffer[size] = 0;

	if (*buffer == '+') {
		nodenum = simple_strtoul(buffer+1, NULL, 10);
		if (clusterip_add_node(c, nodenum))
			return -ENOMEM;
	} else if (*buffer == '-') {
		nodenum = simple_strtoul(buffer+1, NULL,10);
		if (clusterip_del_node(c, nodenum))
			return -ENOENT;
	} else
		return -EIO;

	return size;
}
