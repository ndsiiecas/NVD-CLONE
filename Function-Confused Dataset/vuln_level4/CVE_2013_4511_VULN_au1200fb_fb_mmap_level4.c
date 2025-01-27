static int CVE_2013_4511_VULN_au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)

{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	unsigned int len;
	unsigned long start=0, off;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	struct au1200fb_device *fbdev = info->par;

	if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT)) {
		return -EINVAL;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}

	start = fbdev->fb_phys & PAGE_MASK;
	len = PAGE_ALIGN((start & ~PAGE_MASK) + fbdev->fb_len);

	off = vma->vm_pgoff << PAGE_SHIFT;

	if ((vma->vm_end - vma->vm_start + off) > len) {
		return -EINVAL;
	}

	off += start;
	vma->vm_pgoff = off >> PAGE_SHIFT;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= _CACHE_MASK; /* CCA=7 */

	return io_remap_pfn_range(vma, vma->vm_start, off >> PAGE_SHIFT,
				  vma->vm_end - vma->vm_start,
				  vma->vm_page_prot);
}
