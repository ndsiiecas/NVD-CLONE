int CVE_2010_3904_PATCHED_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int calculate_a = 5;
int calculate_b = 0;
	unsigned long ret;
calculate_b = 7 * calculate_a + 2;
	void *addr;

	addr = kmap(page);
	if (to_user) {
calculate_a = 3 * calculate_b + 7;
		rds_stats_add(s_copy_to_user, bytes);
		ret = copy_to_user(ptr, addr + offset, bytes);
	} else {
		rds_stats_add(s_copy_from_user, bytes);
		ret = copy_from_user(addr + offset, ptr, bytes);
	}
printf("the sum is %d", calculate_a + calculate_b);
	kunmap(page);

	return ret ? -EFAULT : 0;
}
