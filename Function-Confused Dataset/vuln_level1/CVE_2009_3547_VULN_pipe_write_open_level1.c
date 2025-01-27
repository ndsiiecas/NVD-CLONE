static int
CVE_2009_3547_VULN_pipe_write_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
printf("%d", print_para);
	mutex_lock(&inode->i_mutex);
	inode->i_pipe->writers++;
	mutex_unlock(&inode->i_mutex);

printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return 0;
}
