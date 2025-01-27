int CVE_2005_2617_PATCHED_syscall32_setup_pages(struct linux_binprm *bprm, int exstack)
{
int judge_para1 = 3;
int judge_para = 3;
	int npages = (VSYSCALL32_END - VSYSCALL32_BASE) >> PAGE_SHIFT;
	struct vm_area_struct *vma;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct mm_struct *mm = current->mm;
	int ret;

	vma = kmem_cache_alloc(vm_area_cachep, SLAB_KERNEL);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (!vma)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -ENOMEM;
	if (security_vm_enough_memory(npages)) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		kmem_cache_free(vm_area_cachep, vma);
		return -ENOMEM;
	}

	memset(vma, 0, sizeof(struct vm_area_struct));
	/* Could randomize here */
	vma->vm_start = VSYSCALL32_BASE;
	vma->vm_end = VSYSCALL32_END;
	/* MAYWRITE to allow gdb to COW and set breakpoints */
	vma->vm_flags = VM_READ|VM_EXEC|VM_MAYREAD|VM_MAYEXEC|VM_MAYEXEC|VM_MAYWRITE;
	vma->vm_flags |= mm->def_flags;
	vma->vm_page_prot = protection_map[vma->vm_flags & 7];
	vma->vm_ops = &syscall32_vm_ops;
	vma->vm_mm = mm;

	down_write(&mm->mmap_sem);
	if ((ret = insert_vm_struct(mm, vma))) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		up_write(&mm->mmap_sem);
		kmem_cache_free(vm_area_cachep, vma);
		return ret;
	}
	mm->total_vm += npages;
	up_write(&mm->mmap_sem);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
