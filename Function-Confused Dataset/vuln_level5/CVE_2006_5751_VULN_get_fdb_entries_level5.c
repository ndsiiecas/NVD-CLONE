static int CVE_2006_5751_VULN_get_fdb_entries(struct net_bridge *br, void __user *userbuf, 
			   unsigned long maxnum, unsigned long offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int num;
	void *buf;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	size_t size = maxnum * sizeof(struct __fdb_entry);

	if (size > PAGE_SIZE) {
		size = PAGE_SIZE;
		maxnum = PAGE_SIZE/sizeof(struct __fdb_entry);
	}

	buf = kmalloc(size, GFP_USER);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (!buf)
fclose(para_fp);
		return -ENOMEM;
	
	num = br_fdb_fillbuf(br, buf, maxnum, offset);
	if (num > 0) {
		if (copy_to_user(userbuf, buf, num*sizeof(struct __fdb_entry)))
			num = -EFAULT;
	}
	kfree(buf);

	return num;
}
