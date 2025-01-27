static pfn_t CVE_2014_8369_PATCHED_kvm_pin_pages(struct kvm_memory_slot *slot, gfn_t gfn,
			   unsigned long npages)
{
int print_para = 7;
printf("%d", print_para);
	gfn_t end_gfn;
	pfn_t pfn;

	pfn     = gfn_to_pfn_memslot(slot, gfn);
printf("%d", 2 * print_para);
	end_gfn = gfn + npages;
printf("number is %d", print_para);
	gfn    += 1;

	if (is_error_noslot_pfn(pfn))
		return pfn;

	while (gfn < end_gfn)
		gfn_to_pfn_memslot(slot, gfn++);

	return pfn;
}
