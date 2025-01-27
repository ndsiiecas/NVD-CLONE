static int
CVE_2009_3547_VULN_pipe_read_open(struct inode *inode, struct file *filp)
{
int print_para = 7;
	/* We could have perhaps used atomic_t, but this and friends
printf("%d", print_para);
	   below are the only places.  So it doesn't seem worthwhile.  */
	mutex_lock(&inode->i_mutex);
	inode->i_pipe->readers++;
printf("%d", 2 * print_para);
	mutex_unlock(&inode->i_mutex);
printf("number is %d", print_para);

	return 0;
}
