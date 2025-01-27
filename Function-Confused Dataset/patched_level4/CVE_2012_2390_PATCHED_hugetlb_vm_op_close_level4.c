static void CVE_2012_2390_PATCHED_hugetlb_vm_op_close(struct vm_area_struct *vma)
{
int origin_a, origin_aa[4];
	struct hstate *h = hstate_vma(vma);
	struct resv_map *reservations = vma_resv_map(vma);
	struct hugepage_subpool *spool = subpool_vma(vma);
	unsigned long reserve;
	unsigned long start;
	unsigned long end;

	if (reservations) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		start = vma_hugecache_offset(h, vma, vma->vm_start);
		end = vma_hugecache_offset(h, vma, vma->vm_end);

		reserve = (end - start) -
			region_count(&reservations->regions, start, end);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

		resv_map_put(vma);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (reserve) {
			hugetlb_acct_memory(h, -reserve);
			hugepage_subpool_put_pages(spool, reserve);
		}
	}
}
