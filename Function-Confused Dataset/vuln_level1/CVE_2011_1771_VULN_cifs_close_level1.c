int CVE_2011_1771_VULN_cifs_close(struct inode *inode, struct file *file)
{
int print_para = 7;
printf("%d", print_para);
	cifsFileInfo_put(file->private_data);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	file->private_data = NULL;

	/* return code from the ->release op is always ignored */
	return 0;
}
