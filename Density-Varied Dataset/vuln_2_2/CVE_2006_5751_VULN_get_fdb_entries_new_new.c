static int CVE_2006_5751_VULN_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int num;
	void *buf;
	size_t size = maxnum * sizeof(struct __fdb_entry);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (size > PAGE_SIZE) {
		size = PAGE_SIZE;
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);
	}

	buf = kmalloc(size, GFP_USER);
	if (!buf)
		return -ENOMEM;
	
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			num = -EFAULT;
	}
	kfree(buf);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return num;
}
