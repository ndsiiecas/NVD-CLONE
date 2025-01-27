static ssize_t CVE_2013_4512_VULN_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int origin_a, origin_aa[4];
	char *end, buf[sizeof("nnnnn\0")];
	int tmp;

	if (copy_from_user(buf, buffer, count))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return -EFAULT;

	tmp = simple_strtol(buf, &end, 0);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;

	uml_exitcode = tmp;
	return count;
}
