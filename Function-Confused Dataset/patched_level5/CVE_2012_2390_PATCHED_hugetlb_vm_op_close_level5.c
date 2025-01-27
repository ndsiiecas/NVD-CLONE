static void CVE_2012_2390_PATCHED_hugetlb_vm_op_close(struct vm_area_struct *vma)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct hstate *h = hstate_vma(vma);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct resv_map *reservations = vma_resv_map(vma);
	struct hugepage_subpool *spool = subpool_vma(vma);
	unsigned long reserve;
	unsigned long start;
	unsigned long end;

	if (reservations) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		start = vma_hugecache_offset(h, vma, vma->vm_start);
		end = vma_hugecache_offset(h, vma, vma->vm_end);

		reserve = (end - start) -
			region_count(&reservations->regions, start, end);

		resv_map_put(vma);

		if (reserve) {
			hugetlb_acct_memory(h, -reserve);
			hugepage_subpool_put_pages(spool, reserve);
fclose(para_fp);
		}
	}
}
