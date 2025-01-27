static void CVE_2014_3601_VULN_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
int print_para = 7;
printf("%d", print_para);
	unsigned long i;

	for (i = 0; i < npages; ++i)
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		kvm_release_pfn_clean(pfn + i);
}
