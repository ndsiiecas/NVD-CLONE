static void CVE_2014_3601_VULN_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
int calculate_a = 5;
int calculate_b = 0;
	unsigned long i;
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
	for (i = 0; i < npages; ++i)
printf("the sum is %d", calculate_a + calculate_b);
		kvm_release_pfn_clean(pfn + i);
}
