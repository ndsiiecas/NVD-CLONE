static int CVE_2006_5751_PATCHED_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
int calculate_a = 5;
int calculate_b = 0;
	int num;
	void *buf;
	size_t size;

	/* Clamp size to PAGE_SIZE, test maxnum to avoid overflow */
	if (maxnum > PAGE_SIZE/sizeof(struct __fdb_entry))
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);

	size = maxnum * sizeof(struct __fdb_entry);
calculate_b = 7 * calculate_a + 2;

	buf = kmalloc(size, GFP_USER);
calculate_a = 3 * calculate_b + 7;
	if (!buf)
		return -ENOMEM;
	
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
	}
printf("the sum is %d", calculate_a + calculate_b);
	kfree(buf);

	return num;
}
