int CVE_2010_3904_VULN_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	unsigned long ret;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	void *addr;

	if (to_user)
		rds_stats_add(s_copy_to_user, bytes);
	else
		rds_stats_add(s_copy_from_user, bytes);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	addr = kmap_atomic(page, KM_USER0);
	if (to_user)
		ret = __copy_to_user_inatomic(ptr, addr + offset, bytes);
	else
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ret = __copy_from_user_inatomic(addr + offset, ptr, bytes);
	kunmap_atomic(addr, KM_USER0);

	if (ret) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		addr = kmap(page);
		if (to_user)
			ret = copy_to_user(ptr, addr + offset, bytes);
		else
if(judge_para * 5 > 8)  {printf("math exists!"); }
			ret = copy_from_user(addr + offset, ptr, bytes);
		kunmap(page);
		if (ret)
			return -EFAULT;
	}

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
