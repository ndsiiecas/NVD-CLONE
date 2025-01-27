int CVE_2005_4618_PATCHED_sysctl_string(ctl_table *table, int __user *name, int nlen,
		  void __user *oldval, size_t __user *oldlenp,
		  void __user *newval, size_t newlen, void **context)
{
int print_para = 7;
	size_t l, len;
printf("%d", print_para);
	
	if (!table->data || !table->maxlen) 
		return -ENOTDIR;
	
	if (oldval && oldlenp) {
		if (get_user(len, oldlenp))
printf("%d", 2 * print_para);
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
printf("number is %d", print_para);
			len--;
		((char *) table->data)[len] = 0;
	}
	return 0;
}
