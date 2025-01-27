static void CVE_2014_3601_VULN_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long i;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	for (i = 0; i < npages; ++i)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		kvm_release_pfn_clean(pfn + i);
}
