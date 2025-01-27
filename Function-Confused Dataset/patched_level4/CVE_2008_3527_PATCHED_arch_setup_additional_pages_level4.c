int CVE_2008_3527_PATCHED_arch_setup_additional_pages(struct linux_binprm *bprm, int exstack)
{
int origin_a, origin_aa[4];
	struct mm_struct *mm = current->mm;
	unsigned long addr;
	int ret;

	down_write(&mm->mmap_sem);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	addr = get_unmapped_area(NULL, 0, PAGE_SIZE, 0, 0);
	if (IS_ERR_VALUE(addr)) {
		ret = addr;
		goto up_fail;
	}

	/*
	 * MAYWRITE to allow gdb to COW and set breakpoints
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 *
	 * Make sure the vDSO gets into every core dump.
	 * Dumping its contents makes post-mortem fully interpretable later
	 * without matching up the same kernel and hardware config to see
	 * what PC values meant.
	 */
	ret = install_special_mapping(mm, addr, PAGE_SIZE,
				      VM_READ|VM_EXEC|
				      VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC|
				      VM_ALWAYSDUMP,
				      syscall_pages);
	if (ret)
		goto up_fail;

	current->mm->context.vdso = (void *)addr;
	current_thread_info()->sysenter_return =
				    (void *)VDSO_SYM(&SYSENTER_RETURN);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
up_fail:
	up_write(&mm->mmap_sem);
	return ret;
}
