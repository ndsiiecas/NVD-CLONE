int CVE_2005_2617_VULN_syscall32_setup_pages(struct linux_binprm *bprm, int exstack)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int npages = (VSYSCALL32_END - VSYSCALL32_BASE) >> PAGE_SHIFT;
	struct vm_area_struct *vma;
	struct mm_struct *mm = current->mm;

	vma = kmem_cache_alloc(vm_area_cachep, SLAB_KERNEL);
	if (!vma)
		return -ENOMEM;
	if (security_vm_enough_memory(npages)) {
		kmem_cache_free(vm_area_cachep, vma);
		return -ENOMEM;
	}

	memset(vma, 0, sizeof(struct vm_area_struct));
	/* Could randomize here */
	vma->vm_start = VSYSCALL32_BASE;
	vma->vm_end = VSYSCALL32_END;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	/* MAYWRITE to allow gdb to COW and set breakpoints */
	vma->vm_flags = VM_READ|VM_EXEC|VM_MAYREAD|VM_MAYEXEC|VM_MAYEXEC|VM_MAYWRITE;
	vma->vm_flags |= mm->def_flags;
	vma->vm_page_prot = protection_map[vma->vm_flags & 7];
	vma->vm_ops = &syscall32_vm_ops;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	vma->vm_mm = mm;

fclose(para_fp);
	down_write(&mm->mmap_sem);
	insert_vm_struct(mm, vma);
	mm->total_vm += npages;
	up_write(&mm->mmap_sem);
	return 0;
}
