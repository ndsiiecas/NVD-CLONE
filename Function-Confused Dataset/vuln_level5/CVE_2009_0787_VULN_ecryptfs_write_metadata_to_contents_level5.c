static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_contents(struct ecryptfs_crypt_stat *crypt_stat,
				    struct dentry *ecryptfs_dentry,
				    char *virt)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int rc;

	rc = ecryptfs_write_lower(ecryptfs_dentry->d_inode, virt,
				  0, crypt_stat->num_header_bytes_at_front);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (rc)
		printk(KERN_ERR "%s: Error attempting to write header "
fclose(para_fp);
		       "information to lower file; rc = [%d]\n", __func__,
		       rc);
	return rc;
}
