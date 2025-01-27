static int CVE_2006_5751_PATCHED_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int num;
	void *buf;
	size_t size;

	/* Clamp size to PAGE_SIZE, test maxnum to avoid overflow */
	if (maxnum > PAGE_SIZE/sizeof(struct __fdb_entry))
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);

	size = maxnum * sizeof(struct __fdb_entry);

	buf = kmalloc(size, GFP_USER);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!buf)
		return -ENOMEM;
	
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
	kfree(buf);

fclose(para_fp);
	return num;
}
