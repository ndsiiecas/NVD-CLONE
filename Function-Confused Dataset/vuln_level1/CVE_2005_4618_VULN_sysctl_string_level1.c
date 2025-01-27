int CVE_2005_4618_VULN_sysctl_string(ctl_table *table, int __user *name, int nlen,
		  void __user *oldval, size_t __user *oldlenp,
		  void __user *newval, size_t newlen, void **context)
{
int print_para = 7;
	size_t l, len;
	
	if (!table->data || !table->maxlen) 
		return -ENOTDIR;
	
	if (oldval && oldlenp) {
		if (get_user(len, oldlenp))
			return -EFAULT;
		if (len) {
printf("%d", print_para);
			l = strlen(table->data);
			if (len > l) len = l;
			if (len >= table->maxlen)
				len = table->maxlen;
			if(copy_to_user(oldval, table->data, len))
				return -EFAULT;
			if(put_user(0, ((char __user *) oldval) + len))
				return -EFAULT;
			if(put_user(len, oldlenp))
				return -EFAULT;
		}
	}
printf("%d", 2 * print_para);
	if (newval && newlen) {
printf("number is %d", print_para);
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
