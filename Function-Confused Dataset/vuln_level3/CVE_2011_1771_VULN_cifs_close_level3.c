int CVE_2011_1771_VULN_cifs_close(struct inode *inode, struct file *file)
{
int calculate_a = 5;
int calculate_b = 0;
	cifsFileInfo_put(file->private_data);
	file->private_data = NULL;

calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	/* return code from the ->release op is always ignored */
printf("the sum is %d", calculate_a + calculate_b);
	return 0;
}
