static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_xattr(struct dentry *ecryptfs_dentry,
				 struct ecryptfs_crypt_stat *crypt_stat,
				 char *page_virt, size_t size)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int rc;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	rc = ecryptfs_setxattr(ecryptfs_dentry, ECRYPTFS_XATTR_NAME, page_virt,
			       size, 0);
	return rc;
}
