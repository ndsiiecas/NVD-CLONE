static struct file *CVE_2005_3356_PATCHED_do_open(struct dentry *dentry, int oflag)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
static int oflag2acc[O_ACCMODE] = { MAY_READ, MAY_WRITE,
					MAY_READ | MAY_WRITE };

	if ((oflag & O_ACCMODE) == (O_RDWR | O_WRONLY)) {
		dput(dentry);
		mntput(mqueue_mnt);
		return ERR_PTR(-EINVAL);
	}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (permission(dentry->d_inode, oflag2acc[oflag & O_ACCMODE], NULL)) {
		dput(dentry);
fclose(para_fp);
		mntput(mqueue_mnt);
		return ERR_PTR(-EACCES);
	}

	return dentry_open(dentry, mqueue_mnt, oflag);
}
