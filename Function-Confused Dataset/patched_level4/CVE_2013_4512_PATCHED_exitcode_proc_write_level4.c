static ssize_t CVE_2013_4512_PATCHED_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int origin_a, origin_aa[4];
	char *end, buf[sizeof("nnnnn\0")];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	size_t size;
	int tmp;

	size = min(count, sizeof(buf));
	if (copy_from_user(buf, buffer, size))
		return -EFAULT;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		return -EINVAL;

	uml_exitcode = tmp;
	return count;
}
