static ssize_t CVE_2012_0056_PATCHED_mem_write(struct file * file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int copied;
	char *page;
	unsigned long dst = *ppos;
	struct mm_struct *mm = file->private_data;

	if (!mm)
		return 0;

	page = (char *)__get_free_page(GFP_TEMPORARY);
	if (!page)
		return -ENOMEM;

	copied = 0;
	while (count > 0) {
		int this_len, retval;

		this_len = (count > PAGE_SIZE) ? PAGE_SIZE : count;
		if (copy_from_user(page, buf, this_len)) {
			copied = -EFAULT;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		}
		retval = access_remote_vm(mm, dst, page, this_len, 1);
		if (!retval) {
			if (!copied)
				copied = -EIO;
			break;
		}
		copied += retval;
		buf += retval;
		dst += retval;
		count -= retval;			
	}
	*ppos = dst;

	free_page((unsigned long) page);
fclose(para_fp);
	return copied;
}
