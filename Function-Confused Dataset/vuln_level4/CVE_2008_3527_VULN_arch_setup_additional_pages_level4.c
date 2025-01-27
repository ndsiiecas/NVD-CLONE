int CVE_2008_3527_VULN_arch_setup_additional_pages(struct linux_binprm *bprm, int exstack)
{
int origin_a, origin_aa[4];
	struct vm_area_struct *vma;
	struct mm_struct *mm = current->mm;
	unsigned long addr;
	int ret;

	down_write(&mm->mmap_sem);
	addr = get_unmapped_area(NULL, 0, PAGE_SIZE, 0, 0);
	if (IS_ERR_VALUE(addr)) {
		ret = addr;
		goto up_fail;
	}

	vma = kmem_cache_zalloc(vm_area_cachep, GFP_KERNEL);
	if (!vma) {
		ret = -ENOMEM;
		goto up_fail;
	}

	vma->vm_start = addr;
	vma->vm_end = addr + PAGE_SIZE;
	/* MAYWRITE to allow gdb to COW and set breakpoints */
	vma->vm_flags = VM_READ|VM_EXEC|VM_MAYREAD|VM_MAYEXEC|VM_MAYWRITE;
	/*
	 * Make sure the vDSO gets into every core dump.
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	 * Dumping its contents makes post-mortem fully interpretable later
	 * without matching up the same kernel and hardware config to see
	 * what PC values meant.
	 */
	vma->vm_flags |= VM_ALWAYSDUMP;
	vma->vm_flags |= mm->def_flags;
	vma->vm_page_prot = protection_map[vma->vm_flags & 7];
	vma->vm_ops = &syscall_vm_ops;
	vma->vm_mm = mm;

	ret = insert_vm_struct(mm, vma);
	if (unlikely(ret)) {
		kmem_cache_free(vm_area_cachep, vma);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		goto up_fail;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}

	current->mm->context.vdso = (void *)addr;
	current_thread_info()->sysenter_return =
				    (void *)VDSO_SYM(&SYSENTER_RETURN);
	mm->total_vm++;
up_fail:
	up_write(&mm->mmap_sem);
	return ret;
}
