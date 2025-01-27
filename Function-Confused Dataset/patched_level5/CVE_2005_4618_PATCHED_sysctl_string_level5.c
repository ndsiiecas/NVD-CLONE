int CVE_2005_4618_PATCHED_sysctl_string(ctl_table *table, int __user *name, int nlen,
		  void __user *oldval, size_t __user *oldlenp,
		  void __user *newval, size_t newlen, void **context)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	size_t l, len;
	
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!table->data || !table->maxlen) 
		return -ENOTDIR;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	
	if (oldval && oldlenp) {
fclose(para_fp);
		if (get_user(len, oldlenp))
			return -EFAULT;
		if (len) {
			l = strlen(table->data)+1;
			if (len > l) len = l;
			if (len >= table->maxlen)
				len = table->maxlen;
			if(copy_to_user(oldval, table->data, len))
				return -EFAULT;
			if(put_user(len, oldlenp))
				return -EFAULT;
		}
	}
	if (newval && newlen) {
		len = newlen;
		if (len > table->maxlen)
			len = table->maxlen;
		if(copy_from_user(table->data, newval, len))
			return -EFAULT;
		if (len == table->maxlen)
			len--;
		((char *) table->data)[len] = 0;
	}
	return 0;
}
