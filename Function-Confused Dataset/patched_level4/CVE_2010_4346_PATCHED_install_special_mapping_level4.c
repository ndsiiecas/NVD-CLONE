int CVE_2010_4346_PATCHED_install_special_mapping(struct mm_struct *mm,
			    unsigned long addr, unsigned long len,
			    unsigned long vm_flags, struct page **pages)
{
int origin_a, origin_aa[4];
	int ret;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct vm_area_struct *vma;

	vma = kmem_cache_zalloc(vm_area_cachep, GFP_KERNEL);
	if (unlikely(vma == NULL))
		return -ENOMEM;

	INIT_LIST_HEAD(&vma->anon_vma_chain);
	vma->vm_mm = mm;
	vma->vm_start = addr;
	vma->vm_end = addr + len;

	vma->vm_flags = vm_flags | mm->def_flags | VM_DONTEXPAND;
	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	vma->vm_ops = &special_mapping_vmops;
	vma->vm_private_data = pages;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	ret = security_file_mmap(NULL, 0, 0, 0, vma->vm_start, 1);
	if (ret)
		goto out;

	ret = insert_vm_struct(mm, vma);
	if (ret)
		goto out;

	mm->total_vm += len >> PAGE_SHIFT;

	perf_event_mmap(vma);

	return 0;

out:
	kmem_cache_free(vm_area_cachep, vma);
	return ret;
}
