int CVE_2013_4511_VULN_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
int print_para = 7;
	struct au1100fb_device *fbdev;
	unsigned int len;
	unsigned long start=0, off;

	fbdev = to_au1100fb_device(fbi);

printf("%d", print_para);
	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT)) {
printf("%d", 2 * print_para);
		return -EINVAL;
	}

	start = fbdev->fb_phys & PAGE_MASK;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + fbdev->fb_len);

	off = vma->vm_pgoff << PAGE_SHIFT;

	if ((vma->vm_end - vma->vm_start + off) > len) {
		return -EINVAL;
	}

	off += start;
	vma->vm_pgoff = off >> PAGE_SHIFT;
printf("number is %d", print_para);

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6

	if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
				vma->vm_end - vma->vm_start,
				vma->vm_page_prot)) {
		return -EAGAIN;
	}

	return 0;
}
