int CVE_2013_4511_PATCHED_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
int calculate_a = 5;
int calculate_b = 0;
	struct au1100fb_device *fbdev;

calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	fbdev = to_au1100fb_device(fbi);

printf("the sum is %d", calculate_a + calculate_b);
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6

	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
