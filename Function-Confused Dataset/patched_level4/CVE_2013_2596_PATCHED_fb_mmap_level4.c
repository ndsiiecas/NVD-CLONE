static int
CVE_2013_2596_PATCHED_fb_mmap(struct file *file, struct vm_area_struct * vma)
{
int origin_a, origin_aa[4];
	struct fb_info *info = file_fb_info(file);
	struct fb_ops *fb;
	unsigned long mmio_pgoff;
	unsigned long start;
	u32 len;

	if (!info)
		return -ENODEV;
	fb = info->fbops;
	if (!fb)
		return -ENODEV;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	mutex_lock(&info->mm_lock);
	if (fb->CVE_2013_2596_PATCHED_fb_mmap) {
		int res;
		res = fb->CVE_2013_2596_PATCHED_fb_mmap(info, vma);
		mutex_unlock(&info->mm_lock);
		return res;
	}

	/*
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * Ugh. This can be either the frame buffer mapping, or
	 * if pgoff points past it, the mmio mapping.
	 */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	start = info->fix.smem_start;
	len = info->fix.smem_len;
	mmio_pgoff = PAGE_ALIGN((start & ~PAGE_MASK) + len) >> PAGE_SHIFT;
	if (vma->vm_pgoff >= mmio_pgoff) {
		vma->vm_pgoff -= mmio_pgoff;
		start = info->fix.mmio_start;
		len = info->fix.mmio_len;
	}
	mutex_unlock(&info->mm_lock);

	vma->vm_page_prot = vm_get_page_prot(vma->vm_flags);
	fb_pgprotect(file, vma, start);

	return vm_iomap_memory(vma, start, len);
}
