static int
CVE_2009_0787_PATCHED_ecryptfs_write_metadata_to_xattr(struct dentry *ecryptfs_dentry,
				 char *page_virt, size_t size)
{
int print_para = 7;
printf("%d", print_para);
	int rc;

	rc = ecryptfs_setxattr(ecryptfs_dentry, ECRYPTFS_XATTR_NAME, page_virt,
			       size, 0);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return rc;
}
