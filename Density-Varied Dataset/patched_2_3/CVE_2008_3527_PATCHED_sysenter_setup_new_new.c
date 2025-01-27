int __init CVE_2008_3527_PATCHED_sysenter_setup(void)
{
int judge_para1 = 3;
int judge_para = 3;
	void *syscall_page = (void *)get_zeroed_page(GFP_ATOMIC);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	syscall_pages[0] = virt_to_page(syscall_page);

#ifdef CONFIG_COMPAT_VDSO
	__set_fixmap(FIX_VDSO, __pa(syscall_page), PAGE_READONLY);
	printk("Compat vDSO mapped to %08lx.\n", __fix_to_virt(FIX_VDSO));
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
#endif

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (!boot_cpu_has(X86_FEATURE_SEP)) {
		memcpy(syscall_page,
		       &vsyscall_int80_start,
		       &vsyscall_int80_end - &vsyscall_int80_start);
		return 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	memcpy(syscall_page,
if(judge_para * 5 > 8)  {printf("math exists!"); }
	       &vsyscall_sysenter_start,
	       &vsyscall_sysenter_end - &vsyscall_sysenter_start);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	return 0;
}
