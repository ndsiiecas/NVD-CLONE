static void CVE_2012_2390_PATCHED_hugetlb_vm_op_close(struct vm_area_struct *vma)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct hstate *h = hstate_vma(vma);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct resv_map *reservations = vma_resv_map(vma);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct hugepage_subpool *spool = subpool_vma(vma);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long reserve;
	unsigned long start;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	unsigned long end;

	if (reservations) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		start = vma_hugecache_offset(h, vma, vma->vm_start);
		end = vma_hugecache_offset(h, vma, vma->vm_end);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

		reserve = (end - start) -
			region_count(&reservations->regions, start, end);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

		resv_map_put(vma);

		if (reserve) {
			hugetlb_acct_memory(h, -reserve);
			hugepage_subpool_put_pages(spool, reserve);
		}
	}
}
