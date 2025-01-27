static ssize_t CVE_2012_0056_PATCHED_mem_write(struct file * file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
int calculate_a = 5;
int calculate_b = 0;
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
calculate_b = 7 * calculate_a + 2;
		int this_len, retval;

		this_len = (count > PAGE_SIZE) ? PAGE_SIZE : count;
		if (copy_from_user(page, buf, this_len)) {
			copied = -EFAULT;
			break;
		}
		retval = access_remote_vm(mm, dst, page, this_len, 1);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
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
	return copied;
}
