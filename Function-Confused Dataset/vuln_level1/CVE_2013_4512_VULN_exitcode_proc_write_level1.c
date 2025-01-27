static ssize_t CVE_2013_4512_VULN_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int print_para = 7;
	char *end, buf[sizeof("nnnnn\0")];
printf("%d", print_para);
	int tmp;

	if (copy_from_user(buf, buffer, count))
		return -EFAULT;

	tmp = simple_strtol(buf, &end, 0);
printf("%d", 2 * print_para);
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;

	uml_exitcode = tmp;
printf("number is %d", print_para);
	return count;
}
