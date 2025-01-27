static void CVE_2014_3601_PATCHED_kvm_unpin_pages(struct kvm *kvm, pfn_t pfn, unsigned long npages)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	unsigned long i;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	for (i = 0; i < npages; ++i)
		kvm_release_pfn_clean(pfn + i);
}
