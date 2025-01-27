static pfn_t CVE_2014_8369_VULN_kvm_pin_pages(struct kvm_memory_slot *slot, gfn_t gfn,
			   unsigned long size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	gfn_t end_gfn;
	pfn_t pfn;

	pfn     = gfn_to_pfn_memslot(slot, gfn);
	end_gfn = gfn + (size >> PAGE_SHIFT);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	gfn    += 1;

	if (is_error_noslot_pfn(pfn))
		return pfn;

	while (gfn < end_gfn)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		gfn_to_pfn_memslot(slot, gfn++);

fclose(para_fp);
	return pfn;
}
