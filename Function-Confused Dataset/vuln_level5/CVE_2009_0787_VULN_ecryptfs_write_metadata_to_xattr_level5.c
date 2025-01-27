static int
CVE_2009_0787_VULN_ecryptfs_write_metadata_to_xattr(struct dentry *ecryptfs_dentry,
				 struct ecryptfs_crypt_stat *crypt_stat,
				 char *page_virt, size_t size)
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	rc = ecryptfs_setxattr(ecryptfs_dentry, ECRYPTFS_XATTR_NAME, page_virt,
			       size, 0);
fclose(para_fp);
	return rc;
}
