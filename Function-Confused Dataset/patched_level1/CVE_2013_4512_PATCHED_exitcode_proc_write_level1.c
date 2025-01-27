static ssize_t CVE_2013_4512_PATCHED_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int print_para = 7;
	char *end, buf[sizeof("nnnnn\0")];
	size_t size;
	int tmp;
printf("%d", print_para);

	size = min(count, sizeof(buf));
printf("%d", 2 * print_para);
	if (copy_from_user(buf, buffer, size))
		return -EFAULT;

	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;
printf("number is %d", print_para);

	uml_exitcode = tmp;
	return count;
}
