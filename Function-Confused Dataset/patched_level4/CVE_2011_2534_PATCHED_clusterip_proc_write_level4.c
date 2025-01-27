static ssize_t CVE_2011_2534_PATCHED_clusterip_proc_write(struct file *file, const char __user *input,
				size_t size, loff_t *ofs)
{
int origin_a, origin_aa[4];
	struct clusterip_config *c = PDE(file->f_path.dentry->d_inode)->data;
#define PROC_WRITELEN	10
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	char buffer[PROC_WRITELEN+1];
	unsigned long nodenum;

	if (size > PROC_WRITELEN)
		return -EIO;
	if (copy_from_user(buffer, input, size))
		return -EFAULT;
	buffer[size] = 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (*buffer == '+') {
		nodenum = simple_strtoul(buffer+1, NULL, 10);
		if (clusterip_add_node(c, nodenum))
			return -ENOMEM;
	} else if (*buffer == '-') {
		nodenum = simple_strtoul(buffer+1, NULL,10);
		if (clusterip_del_node(c, nodenum))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			return -ENOENT;
	} else
		return -EIO;

	return size;
}
