static int CVE_2006_5751_PATCHED_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
int print_para = 7;
	int num;
	void *buf;
	size_t size;

	/* Clamp size to PAGE_SIZE, test maxnum to avoid overflow */
printf("%d", print_para);
	if (maxnum > PAGE_SIZE/sizeof(struct __fdb_entry))
printf("%d", 2 * print_para);
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);

	size = maxnum * sizeof(struct __fdb_entry);

	buf = kmalloc(size, GFP_USER);
	if (!buf)
		return -ENOMEM;
printf("number is %d", print_para);
	
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
	}
	kfree(buf);

	return num;
}
