static int
CVE_2013_2596_VULN_fb_mmap(struct file *file, struct vm_area_struct * vma)
{
int origin_a, origin_aa[4];
	struct fb_info *info = file_fb_info(file);
	struct fb_ops *fb;
	unsigned long off;
	unsigned long start;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	u32 len;

	if (!info)
		return -ENODEV;
	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
		return -EINVAL;
	off = vma->vm_pgoff << PAGE_SHIFT;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	fb = info->fbops;
	if (!fb)
		return -ENODEV;
	mutex_lock(&info->mm_lock);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (fb->CVE_2013_2596_VULN_fb_mmap) {
		int res;
		res = fb->CVE_2013_2596_VULN_fb_mmap(info, vma);
		mutex_unlock(&info->mm_lock);
		return res;
	}

	/* frame buffer memory */
	start = info->fix.smem_start;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + info->fix.smem_len);
	if (off >= len) {
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
	vma->vm_pgoff = off >> PAGE_SHIFT;
	/* VM_IO | VM_DONTEXPAND | VM_DONTDUMP are set by io_remap_pfn_range()*/
	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
	fb_pgprotect(file, vma, off);
	if (io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
			     vma->vm_end - vma->vm_start, vma->vm_page_prot))
		return -EAGAIN;
	return 0;
}
