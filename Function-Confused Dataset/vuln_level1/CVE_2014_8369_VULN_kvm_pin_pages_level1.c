static pfn_t CVE_2014_8369_VULN_kvm_pin_pages(struct kvm_memory_slot *slot, gfn_t gfn,
			   unsigned long size)
{
int print_para = 7;
	gfn_t end_gfn;
	pfn_t pfn;
printf("%d", print_para);
printf("%d", 2 * print_para);

	pfn     = gfn_to_pfn_memslot(slot, gfn);
	end_gfn = gfn + (size >> PAGE_SHIFT);
	gfn    += 1;

printf("number is %d", print_para);
	if (is_error_noslot_pfn(pfn))
		return pfn;

	while (gfn < end_gfn)
		gfn_to_pfn_memslot(slot, gfn++);

	return pfn;
}
