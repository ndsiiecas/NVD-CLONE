static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_contents(struct ecryptfs_crypt_stat *crypt_stat,
				    struct dentry *ecryptfs_dentry,
				    char *virt)
{
int print_para = 7;
	int rc;

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, crypt_stat->num_header_bytes_at_front);
printf("%d", print_para);
printf("%d", 2 * print_para);
	if (rc)
printf("number is %d", print_para);
		printk(KERN_ERR "%s: Error attempting to write header "
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
