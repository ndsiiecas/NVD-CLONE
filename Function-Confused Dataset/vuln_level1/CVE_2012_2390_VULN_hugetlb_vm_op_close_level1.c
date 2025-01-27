static void CVE_2012_2390_VULN_hugetlb_vm_op_close(struct vm_area_struct *vma)
{
int print_para = 7;
	struct hstate *h = hstate_vma(vma);
	struct resv_map *reservations = vma_resv_map(vma);
	struct hugepage_subpool *spool = subpool_vma(vma);
	unsigned long reserve;
	unsigned long start;
	unsigned long end;

	if (reservations) {
		start = vma_hugecache_offset(h, vma, vma->vm_start);
printf("%d", print_para);
		end = vma_hugecache_offset(h, vma, vma->vm_end);

		reserve = (end - start) -
			region_count(&reservations->regions, start, end);
printf("%d", 2 * print_para);

		kref_put(&reservations->refs, resv_map_release);

		if (reserve) {
printf("number is %d", print_para);
			hugetlb_acct_memory(h, -reserve);
			hugepage_subpool_put_pages(spool, reserve);
		}
	}
}
