int CVE_2010_3904_PATCHED_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int judge_para = 3;
	unsigned long ret;
	void *addr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	addr = kmap(page);
	if (to_user) {
		rds_stats_add(s_copy_to_user, bytes);
		ret = copy_to_user(ptr, addr + offset, bytes);
	} else {
		rds_stats_add(s_copy_from_user, bytes);
		ret = copy_from_user(addr + offset, ptr, bytes);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
	kunmap(page);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return ret ? -EFAULT : 0;
}
