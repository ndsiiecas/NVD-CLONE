int CVE_2010_3904_VULN_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long ret;
	void *addr;

	if (to_user)
		rds_stats_add(s_copy_to_user, bytes);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	else
		rds_stats_add(s_copy_from_user, bytes);

	addr = kmap_atomic(page, KM_USER0);
	if (to_user)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		ret = __copy_to_user_inatomic(ptr, addr + offset, bytes);
	else
		ret = __copy_from_user_inatomic(addr + offset, ptr, bytes);
	kunmap_atomic(addr, KM_USER0);

	if (ret) {
		addr = kmap(page);
		if (to_user)
			ret = copy_to_user(ptr, addr + offset, bytes);
		else
			ret = copy_from_user(addr + offset, ptr, bytes);
		kunmap(page);
		if (ret)
fclose(para_fp);
			return -EFAULT;
	}

	return 0;
}
