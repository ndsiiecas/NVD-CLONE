int CVE_2012_2390_VULN_hugetlb_reserve_pages(struct inode *inode,
					long from, long to,
					struct vm_area_struct *vma,
					vm_flags_t vm_flags)
{
int origin_a, origin_aa[4];
	long ret, chg;
	struct hstate *h = hstate_inode(inode);
	struct hugepage_subpool *spool = subpool_inode(inode);

	/*
	 * Only apply hugepage reservation if asked. At fault time, an
	 * attempt will be made for VM_NORESERVE to allocate a page
	 * without using reserves
	 */
	if (vm_flags & VM_NORESERVE)
		return 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	/*
	 * Shared mappings base their reservation on the number of pages that
	 * are already allocated on behalf of the file. Private mappings need
	 * to reserve the full area even if read-only as mprotect() may be
	 * called to make the mapping read-write. Assume !vma is a shm mapping
	 */
	if (!vma || vma->vm_flags & VM_MAYSHARE)
		chg = region_chg(&inode->i_mapping->private_list, from, to);
	else {
		struct resv_map *resv_map = resv_map_alloc();
		if (!resv_map)
			return -ENOMEM;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		chg = to - from;

		set_vma_resv_map(vma, resv_map);
		set_vma_resv_flags(vma, HPAGE_RESV_OWNER);
	}

	if (chg < 0)
		return chg;

	/* There must be enough pages in the subpool for the mapping */
	if (hugepage_subpool_get_pages(spool, chg))
		return -ENOSPC;

	/*
	 * Check enough hugepages are available for the reservation.
	 * Hand the pages back to the subpool if there are not
	 */
	ret = hugetlb_acct_memory(h, chg);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (ret < 0) {
		hugepage_subpool_put_pages(spool, chg);
		return ret;
	}

	/*
	 * Account for the reservations made. Shared mappings record regions
	 * that have reservations as they are shared by multiple VMAs.
	 * When the last VMA disappears, the region map says how much
	 * the reservation was and the page cache tells how much of
	 * the reservation was consumed. Private mappings are per-VMA and
	 * only the consumed reservations are tracked. When the VMA
	 * disappears, the original reservation is the VMA size and the
	 * consumed reservations are stored in the map. Hence, nothing
	 * else has to be done for private mappings here
	 */
	if (!vma || vma->vm_flags & VM_MAYSHARE)
		region_add(&inode->i_mapping->private_list, from, to);
	return 0;
}
