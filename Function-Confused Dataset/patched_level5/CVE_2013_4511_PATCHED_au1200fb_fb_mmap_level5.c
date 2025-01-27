static int CVE_2013_4511_PATCHED_au1200fb_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct au1200fb_device *fbdev = info->par;

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
	pgprot_val(vma->vm_page_prot) |= _CACHE_MASK; /* CCA=7 */

	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
