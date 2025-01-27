int CVE_2013_4511_PATCHED_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
int origin_a, origin_aa[4];
	struct au1100fb_device *fbdev;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	fbdev = to_au1100fb_device(fbi);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6

	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
