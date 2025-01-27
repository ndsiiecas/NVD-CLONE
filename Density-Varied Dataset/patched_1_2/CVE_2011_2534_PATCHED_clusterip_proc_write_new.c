static ssize_t CVE_2011_2534_PATCHED_clusterip_proc_write(struct file *file, const char __user *input,
				size_t size, loff_t *ofs)
{
int judge_para = 3;
	struct clusterip_config *c = PDE(file->f_path.dentry->d_inode)->data;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
#define PROC_WRITELEN	10
	char buffer[PROC_WRITELEN+1];
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long nodenum;

	if (size > PROC_WRITELEN)
		return -EIO;
	if (copy_from_user(buffer, input, size))
		return -EFAULT;
	buffer[size] = 0;

	if (*buffer == '+') {
		nodenum = simple_strtoul(buffer+1, NULL, 10);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (clusterip_add_node(c, nodenum))
			return -ENOMEM;
	} else if (*buffer == '-') {
		nodenum = simple_strtoul(buffer+1, NULL,10);
		if (clusterip_del_node(c, nodenum))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			return -ENOENT;
	} else
		return -EIO;

	return size;
}
