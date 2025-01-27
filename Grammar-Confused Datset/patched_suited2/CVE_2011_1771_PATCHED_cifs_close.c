int CVE_2011_1771_PATCHED_cifs_close(struct inode *inode, struct file *file)
{
	if (file->private_data != NULL) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		cifsFileInfo_put(file->private_data);
		file->private_data = NULL;
	}

	/* return code from the ->release op is always ignored */
	return 0;
}
