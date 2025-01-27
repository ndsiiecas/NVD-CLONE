int __init CVE_2008_3527_PATCHED_sysenter_setup(void)
{
int origin_a, origin_aa[4];
	void *syscall_page = (void *)get_zeroed_page(GFP_ATOMIC);
	syscall_pages[0] = virt_to_page(syscall_page);

#ifdef CONFIG_COMPAT_VDSO
	__set_fixmap(FIX_VDSO, __pa(syscall_page), PAGE_READONLY);
	printk("Compat vDSO mapped to %08lx.\n", __fix_to_virt(FIX_VDSO));
#endif

	if (!boot_cpu_has(X86_FEATURE_SEP)) {
		memcpy(syscall_page,
		       &vsyscall_int80_start,
		       &vsyscall_int80_end - &vsyscall_int80_start);
		return 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	}

	memcpy(syscall_page,
	       &vsyscall_sysenter_start,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	       &vsyscall_sysenter_end - &vsyscall_sysenter_start);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
