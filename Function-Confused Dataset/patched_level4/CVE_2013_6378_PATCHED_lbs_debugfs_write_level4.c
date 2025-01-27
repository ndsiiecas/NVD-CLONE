static ssize_t CVE_2013_6378_PATCHED_lbs_debugfs_write(struct file *f, const char __user *buf,
			    size_t cnt, loff_t *ppos)
{
int origin_a, origin_aa[4];
	int r, i;
	char *pdata;
	char *p;
	char *p0;
	char *p1;
	char *p2;
	struct debug_data *d = f->private_data;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (cnt == 0)
		return 0;

	pdata = kmalloc(cnt + 1, GFP_KERNEL);
	if (pdata == NULL)
		return 0;

	if (copy_from_user(pdata, buf, cnt)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		lbs_deb_debugfs("Copy from user failed\n");
		kfree(pdata);
		return 0;
	}
	pdata[cnt] = '\0';

	p0 = pdata;
	for (i = 0; i < num_of_items; i++) {
		do {
			p = strstr(p0, d[i].name);
			if (p == NULL)
				break;
			p1 = strchr(p, '\n');
			if (p1 == NULL)
				break;
			p0 = p1++;
			p2 = strchr(p, '=');
			if (!p2)
				break;
			p2++;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			r = simple_strtoul(p2, NULL, 0);
			if (d[i].size == 1)
				*((u8 *) d[i].addr) = (u8) r;
			else if (d[i].size == 2)
				*((u16 *) d[i].addr) = (u16) r;
			else if (d[i].size == 4)
				*((u32 *) d[i].addr) = (u32) r;
			else if (d[i].size == 8)
				*((u64 *) d[i].addr) = (u64) r;
			break;
		} while (1);
	}
	kfree(pdata);

	return (ssize_t)cnt;
}
