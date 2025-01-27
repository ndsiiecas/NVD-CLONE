int CVE_2009_0787_PATCHED_ecryptfs_write_metadata(struct dentry *ecryptfs_dentry)
{
int origin_a, origin_aa[4];
	struct ecryptfs_crypt_stat *crypt_stat =
		&ecryptfs_inode_to_private(ecryptfs_dentry->d_inode)->crypt_stat;
	unsigned int order;
	char *virt;
	size_t virt_len;
	size_t size = 0;
	int rc = 0;

	if (likely(crypt_stat->flags & ECRYPTFS_ENCRYPTED)) {
		if (!(crypt_stat->flags & ECRYPTFS_KEY_VALID)) {
			printk(KERN_ERR "Key is invalid; bailing out\n");
			rc = -EINVAL;
			goto out;
		}
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	} else {
		printk(KERN_WARNING "%s: Encrypted flag not set\n",
		       __func__);
		rc = -EINVAL;
		goto out;
	}
	virt_len = crypt_stat->num_header_bytes_at_front;
	order = get_order(virt_len);
	/* Released in this function */
	virt = (char *)ecryptfs_get_zeroed_pages(GFP_KERNEL, order);
	if (!virt) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		printk(KERN_ERR "%s: Out of memory\n", __func__);
		rc = -ENOMEM;
		goto out;
	}
	rc = ecryptfs_write_headers_virt(virt, virt_len, &size, crypt_stat,
					 ecryptfs_dentry);
	if (unlikely(rc)) {
		printk(KERN_ERR "%s: Error whilst writing headers; rc = [%d]\n",
		       __func__, rc);
		goto out_free;
	}
	if (crypt_stat->flags & ECRYPTFS_METADATA_IN_XATTR)
		rc = ecryptfs_write_metadata_to_xattr(ecryptfs_dentry, virt,
						      size);
	else
		rc = ecryptfs_write_metadata_to_contents(ecryptfs_dentry, virt,
							 virt_len);
	if (rc) {
		printk(KERN_ERR "%s: Error writing metadata out to lower file; "
		       "rc = [%d]\n", __func__, rc);
		goto out_free;
	}
out_free:
	free_pages((unsigned long)virt, order);
out:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return rc;
}
