static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_xattr(struct dentry *ecryptfs_dentry,
				 struct ecryptfs_crypt_stat *crypt_stat,
				 char *page_virt, size_t size)
{
int calculate_a = 5;
int calculate_b = 0;
	int rc;

	rc = ecryptfs_setxattr(ecryptfs_dentry, ECRYPTFS_XATTR_NAME, page_virt,
calculate_b = 7 * calculate_a + 2;
			       size, 0);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return rc;
}
