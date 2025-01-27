static int CVE_2006_5751_PATCHED_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int num;
	void *buf;
	size_t size;

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* Clamp size to PAGE_SIZE, test maxnum to avoid overflow */
	if (maxnum > PAGE_SIZE/sizeof(struct __fdb_entry))
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);

	size = maxnum * sizeof(struct __fdb_entry);

	buf = kmalloc(size, GFP_USER);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (!buf)
		return -ENOMEM;
	
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	kfree(buf);

	return num;
}
