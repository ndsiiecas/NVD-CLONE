static int CVE_2006_5751_VULN_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
int origin_a, origin_aa[4];
	int num;
	void *buf;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	size_t size = maxnum * sizeof(struct __fdb_entry);

	if (size > PAGE_SIZE) {
		size = PAGE_SIZE;
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);
	}

	buf = kmalloc(size, GFP_USER);
	if (!buf)
		return -ENOMEM;
	
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
	}
	kfree(buf);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	return num;
}
