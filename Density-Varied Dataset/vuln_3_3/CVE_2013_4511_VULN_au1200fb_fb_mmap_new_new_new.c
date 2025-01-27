static int CVE_2013_4511_VULN_au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)

{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	unsigned int len;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	unsigned long start=0, off;
	struct au1200fb_device *fbdev = info->par;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT)) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EINVAL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}

	start = fbdev->fb_phys & PAGE_MASK;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + fbdev->fb_len);

	off = vma->vm_pgoff << PAGE_SHIFT;

	if ((vma->vm_end - vma->vm_start + off) > len) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EINVAL;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	off += start;
	vma->vm_pgoff = off >> PAGE_SHIFT;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= _CACHE_MASK; /* CCA=7 */

	return io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
				  vma->vm_end - vma->vm_start,
				  vma->vm_page_prot);
}
