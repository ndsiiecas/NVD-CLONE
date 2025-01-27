int CVE_2010_3904_PATCHED_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
	unsigned long ret;
	void *addr;

	addr = kmap(page);
	if (to_user) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		rds_stats_add(s_copy_to_user, bytes);
		ret = copy_to_user(ptr, addr + offset, bytes);
	} else {
		rds_stats_add(s_copy_from_user, bytes);
		ret = copy_from_user(addr + offset, ptr, bytes);
	}
	kunmap(page);

	return ret ? -EFAULT : 0;
}
