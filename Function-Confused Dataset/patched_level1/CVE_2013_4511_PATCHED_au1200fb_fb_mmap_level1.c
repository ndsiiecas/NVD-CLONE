static int CVE_2013_4511_PATCHED_au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
int print_para = 7;
printf("%d", print_para);
	struct au1200fb_device *fbdev = info->par;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= _CACHE_MASK; /* CCA=7 */
printf("%d", 2 * print_para);

printf("number is %d", print_para);
	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
