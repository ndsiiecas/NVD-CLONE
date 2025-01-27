static int CVE_2013_4511_PATCHED_au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
	struct au1200fb_device *fbdev = info->par;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= _CACHE_MASK; /* CCA=7 */

	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
