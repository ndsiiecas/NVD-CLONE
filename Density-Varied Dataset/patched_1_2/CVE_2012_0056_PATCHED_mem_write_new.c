static ssize_t CVE_2012_0056_PATCHED_mem_write(struct file * file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para * 5 > 8)  {printf("math exists!"); }
	while (count > 0) {
		int this_len, retval;

		this_len = (count > PAGE_SIZE) ? PAGE_SIZE : count;
		if (copy_from_user(page, buf, this_len)) {
			copied = -EFAULT;
			break;
		}
		retval = access_remote_vm(mm, dst, page, this_len, 1);
		if (!retval) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			if (!copied)
				copied = -EIO;
			break;
		}
		copied += retval;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		buf += retval;
		dst += retval;
		count -= retval;			
	}
	*ppos = dst;

	free_page((unsigned long) page);
	return copied;
}
