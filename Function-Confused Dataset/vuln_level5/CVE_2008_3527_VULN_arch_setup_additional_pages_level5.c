int CVE_2008_3527_VULN_arch_setup_additional_pages(struct linux_binprm *bprm, int exstack)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct vm_area_struct *vma;
	struct mm_struct *mm = current->mm;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned long addr;
	int ret;

	down_write(&mm->mmap_sem);
	addr = get_unmapped_area(NULL, 0, PAGE_SIZE, 0, 0);
	if (IS_ERR_VALUE(addr)) {
		ret = addr;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
fclose(para_fp);
		kmem_cache_free(vm_area_cachep, vma);
		goto up_fail;
	}

	current->mm->context.vdso = (void *)addr;
	current_thread_info()->sysenter_return =
				    (void *)VDSO_SYM(&SYSENTER_RETURN);
	mm->total_vm++;
up_fail:
	up_write(&mm->mmap_sem);
	return ret;
}
