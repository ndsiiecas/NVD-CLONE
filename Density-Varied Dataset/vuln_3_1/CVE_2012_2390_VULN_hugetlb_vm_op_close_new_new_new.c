static void CVE_2012_2390_VULN_hugetlb_vm_op_close(struct vm_area_struct *vma)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct hstate *h = hstate_vma(vma);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct resv_map *reservations = vma_resv_map(vma);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	struct hugepage_subpool *spool = subpool_vma(vma);
	unsigned long reserve;
	unsigned long start;
	unsigned long end;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (reservations) {
		start = vma_hugecache_offset(h, vma, vma->vm_start);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		end = vma_hugecache_offset(h, vma, vma->vm_end);

		reserve = (end - start) -
			region_count(&reservations->regions, start, end);

		kref_put(&reservations->refs, resv_map_release);

		if (reserve) {
			hugetlb_acct_memory(h, -reserve);
			hugepage_subpool_put_pages(spool, reserve);
		}
	}
}
