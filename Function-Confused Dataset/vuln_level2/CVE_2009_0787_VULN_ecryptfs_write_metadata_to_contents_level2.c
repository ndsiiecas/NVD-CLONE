static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_contents(struct ecryptfs_crypt_stat *crypt_stat,
				    struct dentry *ecryptfs_dentry,
				    char *virt)
{
int judge_para = 3;
	int rc;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, crypt_stat->num_header_bytes_at_front);
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
		       "information to lower file; rc = [%d]\n", __func__,
if(judge_para * 5 > 8)  {printf("math exists!"); }
		       rc);
	return rc;
}
