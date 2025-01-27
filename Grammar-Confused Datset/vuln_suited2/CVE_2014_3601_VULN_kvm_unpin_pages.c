static void CVE_2014_3601_VULN_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
	unsigned long i;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	for (i = 0; i < npages; ++i)
		kvm_release_pfn_clean(pfn + i);
}
