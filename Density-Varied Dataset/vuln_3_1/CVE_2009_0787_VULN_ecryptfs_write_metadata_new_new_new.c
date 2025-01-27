int CVE_2009_0787_VULN_ecryptfs_write_metadata(struct dentry *ecryptfs_dentry)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct ecryptfs_crypt_stat *crypt_stat =
		&ecryptfs_inode_to_private(ecryptfs_dentry->d_inode)->crypt_stat;
	char *virt;
	size_t size = 0;
	int rc = 0;

	if (likely(crypt_stat->flags & ECRYPTFS_ENCRYPTED)) {
		if (!(crypt_stat->flags & ECRYPTFS_KEY_VALID)) {
			printk(KERN_ERR "Key is invalid; bailing out\n");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			rc = -EINVAL;
			goto out;
		}
	} else {
		printk(KERN_WARNING "%s: Encrypted flag not set\n",
		       __func__);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		rc = -EINVAL;
		goto out;
	}
	/* Released in this function */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	virt = (char *)get_zeroed_page(GFP_KERNEL);
	if (!virt) {
		printk(KERN_ERR "%s: Out of memory\n", __func__);
		rc = -ENOMEM;
		goto out;
	}
	rc = ecryptfs_write_headers_virt(virt, PAGE_CACHE_SIZE, &size,
					 crypt_stat, ecryptfs_dentry);
	if (unlikely(rc)) {
		printk(KERN_ERR "%s: Error whilst writing headers; rc = [%d]\n",
		       __func__, rc);
		goto out_free;
	}
	if (crypt_stat->flags & ECRYPTFS_METADATA_IN_XATTR)
		rc = ecryptfs_write_metadata_to_xattr(ecryptfs_dentry,
						      crypt_stat, virt, size);
	else
		rc = ecryptfs_write_metadata_to_contents(crypt_stat,
							 ecryptfs_dentry, virt);
	if (rc) {
		printk(KERN_ERR "%s: Error writing metadata out to lower file; "
		       "rc = [%d]\n", __func__, rc);
		goto out_free;
	}
out_free:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	free_page((unsigned long)virt);
out:
	return rc;
}
