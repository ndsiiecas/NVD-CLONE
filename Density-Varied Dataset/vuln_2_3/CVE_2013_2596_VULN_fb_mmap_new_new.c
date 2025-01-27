static int
CVE_2013_2596_VULN_fb_mmap(struct file *file, struct vm_area_struct * vma)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct fb_info *info = file_fb_info(file);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct fb_ops *fb;
	unsigned long off;
	unsigned long start;
	u32 len;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (!info)
		return -ENODEV;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
		return -EINVAL;
	off = vma->vm_pgoff << PAGE_SHIFT;
	fb = info->fbops;
	if (!fb)
		return -ENODEV;
	mutex_lock(&info->mm_lock);
	if (fb->CVE_2013_2596_VULN_fb_mmap) {
		int res;
		res = fb->CVE_2013_2596_VULN_fb_mmap(info, vma);
		mutex_unlock(&info->mm_lock);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return res;
	}

	/* frame buffer memory */
	start = info->fix.smem_start;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + info->fix.smem_len);
	if (off >= len) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		/* memory mapped io */
		off -= len;
		if (info->var.accel_flags) {
			mutex_unlock(&info->mm_lock);
			return -EINVAL;
		}
		start = info->fix.mmio_start;
		len = PAGE_ALIGN((start & ~PAGE_MASK) + info->fix.mmio_len);
	}
	mutex_unlock(&info->mm_lock);
	start &= PAGE_MASK;
	if ((vma->vm_end - vma->vm_start + off) > len)
		return -EINVAL;
	off += start;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	vma->vm_pgoff = off >> PAGE_SHIFT;
	/* VM_IO | VM_DONTEXPAND | VM_DONTDUMP are set by io_remap_pfn_range()*/
	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
	fb_pgprotect(file, vma, off);
	if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			     vma->vm_end - vma->vm_start, vma->vm_page_prot))
		return -EAGAIN;
	return 0;
}
