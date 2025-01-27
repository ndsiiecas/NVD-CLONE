int CVE_2010_3904_VULN_rds_page_copy_user(struct page *page, unsigned long offset,
		       void __user *ptr, unsigned long bytes,
		       int to_user)
{
int origin_a, origin_aa[4];
	unsigned long ret;
	void *addr;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (to_user)
		rds_stats_add(s_copy_to_user, bytes);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	else
		rds_stats_add(s_copy_from_user, bytes);

	addr = kmap_atomic(page, KM_USER0);
	if (to_user)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
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
			return -EFAULT;
	}

	return 0;
}
