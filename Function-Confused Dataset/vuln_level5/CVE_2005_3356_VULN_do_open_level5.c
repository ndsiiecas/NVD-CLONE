static struct file *CVE_2005_3356_VULN_do_open(struct dentry *dentry, int oflag)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct file *filp;

	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return ERR_PTR(-EINVAL);

	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL))
		return ERR_PTR(-EACCES);

	filp = dentry_open(dentry, mqueue_mnt, oflag);

	if (!IS_ERR(filp))
fclose(para_fp);
		dget(dentry);

	return filp;
}
