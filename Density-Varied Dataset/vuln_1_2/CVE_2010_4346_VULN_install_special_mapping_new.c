int CVE_2010_4346_VULN_install_special_mapping(struct mm_struct *mm,
			    unsigned long addr, unsigned long len,
			    unsigned long vm_flags, struct page **pages)
{
int judge_para = 3;
	struct vm_area_struct *vma;

	vma = kmem_cache_zalloc(vm_area_cachep, GFP_KERNEL);
	if (unlikely(vma == NULL))
		return -ENOMEM;

	INIT_LIST_HEAD(&vma->anon_vma_chain);
	vma->vm_mm = mm;
	vma->vm_start = addr;
	vma->vm_end = addr + len;

	vma->vm_flags = vm_flags | mm->def_flags | VM_DONTEXPAND;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);

	vma->vm_ops = &special_mapping_vmops;
	vma->vm_private_data = pages;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (unlikely(insert_vm_struct(mm, vma))) {
		kmem_cache_free(vm_area_cachep, vma);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return -ENOMEM;
	}

	mm->total_vm += len >> PAGE_SHIFT;

	perf_event_mmap(vma);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
