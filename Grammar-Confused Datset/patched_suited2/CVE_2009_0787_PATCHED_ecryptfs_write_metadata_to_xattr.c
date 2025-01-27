static int
CVE_2009_0787_PATCHED_ecryptfs_write_metadata_to_xattr(struct dentry *ecryptfs_dentry,
				 char *page_virt, size_t size)
{
	int rc;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	rc = ecryptfs_setxattr(ecryptfs_dentry, ECRYPTFS_XATTR_NAME, page_virt,
			       size, 0);
	return rc;
}
