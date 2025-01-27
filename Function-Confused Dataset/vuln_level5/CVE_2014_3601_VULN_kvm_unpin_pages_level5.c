static void CVE_2014_3601_VULN_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);

	for (i = 0; i < npages; ++i)
		kvm_release_pfn_clean(pfn + i);
}
