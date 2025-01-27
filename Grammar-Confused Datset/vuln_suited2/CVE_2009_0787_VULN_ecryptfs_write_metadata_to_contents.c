static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_contents(struct ecryptfs_crypt_stat *crypt_stat,
				    struct dentry *ecryptfs_dentry,
				    char *virt)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	int rc;

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, crypt_stat->num_header_bytes_at_front);
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
