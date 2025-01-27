static int
CVE_2009_3547_VULN_pipe_rdwr_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
	mutex_lock(&inode->i_mutex);
	if (filp->f_mode & FMODE_READ)
printf("%d", print_para);
printf("%d", 2 * print_para);
		inode->i_pipe->readers++;
	if (filp->f_mode & FMODE_WRITE)
		inode->i_pipe->writers++;
	mutex_unlock(&inode->i_mutex);
printf("number is %d", print_para);

	return 0;
}
