int CVE_2010_3904_PATCHED_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int print_para = 7;
	unsigned long ret;
	void *addr;

printf("%d", print_para);
	addr = kmap(page);
	if (to_user) {
printf("%d", 2 * print_para);
		rds_stats_add(s_copy_to_user, bytes);
		ret = copy_to_user(ptr, addr + offset, bytes);
	} else {
		rds_stats_add(s_copy_from_user, bytes);
printf("number is %d", print_para);
		ret = copy_from_user(addr + offset, ptr, bytes);
	}
	kunmap(page);

	return ret ? -EFAULT : 0;
}
