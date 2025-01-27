static ssize_t CVE_2011_2534_PATCHED_clusterip_proc_write(struct file *file, const char __user *input,
				size_t size, loff_t *ofs)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct clusterip_config *c = PDE(file->f_path.dentry->d_inode)->data;
#define PROC_WRITELEN	10
	char buffer[PROC_WRITELEN+1];
	unsigned long nodenum;

	if (size > PROC_WRITELEN)
		return -EIO;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (copy_from_user(buffer, input, size))
		return -EFAULT;
	buffer[size] = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (*buffer == '+') {
fclose(para_fp);
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
