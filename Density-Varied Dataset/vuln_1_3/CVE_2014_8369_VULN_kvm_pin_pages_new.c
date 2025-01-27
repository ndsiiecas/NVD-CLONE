static pfn_t CVE_2014_8369_VULN_kvm_pin_pages(struct kvm_memory_slot *slot, gfn_t gfn,
			   unsigned long size)
{
int judge_para = 3;
	gfn_t end_gfn;
	pfn_t pfn;

	pfn     = gfn_to_pfn_memslot(slot, gfn);
	end_gfn = gfn + (size >> PAGE_SHIFT);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	gfn    += 1;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (is_error_noslot_pfn(pfn))
		return pfn;
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	while (gfn < end_gfn)
		gfn_to_pfn_memslot(slot, gfn++);

	return pfn;
}
