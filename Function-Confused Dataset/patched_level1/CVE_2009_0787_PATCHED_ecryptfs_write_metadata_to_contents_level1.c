static int
CVE_2009_0787_PATCHED_ecryptfs_write_metadata_to_contents(struct dentry *ecryptfs_dentry,
				    char *virt, size_t virt_len)
{
int print_para = 7;
	int rc;

printf("%d", print_para);
	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, virt_len);
printf("%d", 2 * print_para);
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
printf("number is %d", print_para);
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
