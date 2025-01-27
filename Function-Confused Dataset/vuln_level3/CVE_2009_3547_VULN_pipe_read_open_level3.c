static int
CVE_2009_3547_VULN_pipe_read_open(struct inode *inode, struct file *filp)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	/* We could have perhaps used atomic_t, but this and friends
	   below are the only places.  So it doesn't seem worthwhile.  */
calculate_a = 3 * calculate_b + 7;
	mutex_lock(&inode->i_mutex);
	inode->i_pipe->readers++;
	mutex_unlock(&inode->i_mutex);
printf("the sum is %d", calculate_a + calculate_b);

	return 0;
}
