int CVE_2009_0787_PATCHED_ecryptfs_write_metadata(struct dentry *ecryptfs_dentry)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ecryptfs_crypt_stat *crypt_stat =
		&ecryptfs_inode_to_private(ecryptfs_dentry->d_inode)->crypt_stat;
	unsigned int order;
	char *virt;
	size_t virt_len;
	size_t size = 0;
	int rc = 0;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (likely(crypt_stat->flags & ECRYPTFS_ENCRYPTED)) {
		if (!(crypt_stat->flags & ECRYPTFS_KEY_VALID)) {
			printk(KERN_ERR "Key is invalid; bailing out\n");
			rc = -EINVAL;
			goto out;
		}
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
		printk(KERN_ERR "%s: Out of memory\n", __func__);
		rc = -ENOMEM;
		goto out;
	}
	rc = ecryptfs_write_headers_virt(virt, virt_len, &size, crypt_stat,
					 ecryptfs_dentry);
	if (unlikely(rc)) {
		printk(KERN_ERR "%s: Error whilst writing headers; rc = [%d]\n",
		       __func__, rc);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
fclose(para_fp);
	return rc;
}
