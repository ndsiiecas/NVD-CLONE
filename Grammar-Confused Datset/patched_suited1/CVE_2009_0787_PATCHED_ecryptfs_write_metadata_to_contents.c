static int
CVE_2009_0787_PATCHED_ecryptfs_write_metadata_to_contents(struct dentry *ecryptfs_dentry,
				    char *virt, size_t virt_len)
{
	int rc;

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, virt_len);
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
