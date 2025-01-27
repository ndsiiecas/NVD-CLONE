int CVE_2013_4511_PATCHED_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct au1100fb_device *fbdev;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	fbdev = to_au1100fb_device(fbi);

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6

	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
