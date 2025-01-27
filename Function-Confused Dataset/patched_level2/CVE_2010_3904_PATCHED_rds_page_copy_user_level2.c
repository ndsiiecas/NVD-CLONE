int CVE_2010_3904_PATCHED_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int judge_para = 3;
	unsigned long ret;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	void *addr;

	addr = kmap(page);
	if (to_user) {
		rds_stats_add(s_copy_to_user, bytes);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		ret = copy_to_user(ptr, addr + offset, bytes);
	} else {
		rds_stats_add(s_copy_from_user, bytes);
		ret = copy_from_user(addr + offset, ptr, bytes);
	}
	kunmap(page);

	return ret ? -EFAULT : 0;
}
