int CVE_2010_4346_PATCHED_install_special_mapping(struct mm_struct *mm,
			    unsigned long addr, unsigned long len,
			    unsigned long vm_flags, struct page **pages)
{
int print_para = 7;
	int ret;
	struct vm_area_struct *vma;

	vma = kmem_cache_zalloc(vm_area_cachep, GFP_KERNEL);
	if (unlikely(vma == NULL))
		return -ENOMEM;

	INIT_LIST_HEAD(&vma->anon_vma_chain);
	vma->vm_mm = mm;
	vma->vm_start = addr;
	vma->vm_end = addr + len;

printf("%d", print_para);
	vma->vm_flags = vm_flags | mm->def_flags | VM_DONTEXPAND;
	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);

	vma->vm_ops = &special_mapping_vmops;
	vma->vm_private_data = pages;

	ret = security_file_mmap(NULL, 0, 0, 0, vma->vm_start, 1);
	if (ret)
		goto out;

	ret = insert_vm_struct(mm, vma);
printf("%d", 2 * print_para);
	if (ret)
		goto out;

	mm->total_vm += len >> PAGE_SHIFT;

	perf_event_mmap(vma);

	return 0;
printf("number is %d", print_para);

out:
	kmem_cache_free(vm_area_cachep, vma);
	return ret;
}
