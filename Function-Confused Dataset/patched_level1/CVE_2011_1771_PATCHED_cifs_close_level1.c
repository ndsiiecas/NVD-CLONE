int CVE_2011_1771_PATCHED_cifs_close(struct inode *inode, struct file *file)
{
int print_para = 7;
	if (file->private_data != NULL) {
printf("%d", print_para);
		cifsFileInfo_put(file->private_data);
printf("%d", 2 * print_para);
		file->private_data = NULL;
printf("number is %d", print_para);
	}

	/* return code from the ->release op is always ignored */
	return 0;
}
