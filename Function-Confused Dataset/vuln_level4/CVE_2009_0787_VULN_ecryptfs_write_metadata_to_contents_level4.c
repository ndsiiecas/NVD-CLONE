static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_contents(struct ecryptfs_crypt_stat *crypt_stat,
				    struct dentry *ecryptfs_dentry,
				    char *virt)
{
int origin_a, origin_aa[4];
	int rc;

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
				  0, crypt_stat->num_header_bytes_at_front);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
