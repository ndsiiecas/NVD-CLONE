int CVE_2013_4511_PATCHED_au1100fb_fb_mmap(struct fb_info *fbi, struct vm_area_struct *vma)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct au1100fb_device *fbdev;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	fbdev = to_au1100fb_device(fbi);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	pgprot_val(vma->vm_page_prot) |= (6 << 9); //CCA=6

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return vm_iomap_memory(vma, fbdev->fb_phys, fbdev->fb_len);
}
