static ssize_t CVE_2013_4512_PATCHED_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	char *end, buf[sizeof("nnnnn\0")];
	size_t size;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int tmp;

	size = min(count, sizeof(buf));
	if (copy_from_user(buf, buffer, size))
		return -EFAULT;

	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EINVAL;
fclose(para_fp);

	uml_exitcode = tmp;
	return count;
}
