int CVE_2013_4511_VULN_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
int judge_para1 = 3;
int judge_para = 3;
	struct au1100fb_device *fbdev;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned int len;
	unsigned long start=0, off;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	fbdev = to_au1100fb_device(fbi);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT)) {
		return -EINVAL;
	}

	start = fbdev->fb_phys & PAGE_MASK;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + fbdev->fb_len);

	off = vma->vm_pgoff << PAGE_SHIFT;

	if ((vma->vm_end - vma->vm_start + off) > len) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EINVAL;
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	off += start;
	vma->vm_pgoff = off >> PAGE_SHIFT;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
				vma->vm_end - vma->vm_start,
				vma->vm_page_prot)) {
		return -EAGAIN;
	}

	return 0;
}
