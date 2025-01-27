static ssize_t CVE_2013_4512_PATCHED_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int calculate_a = 5;
int calculate_b = 0;
	char *end, buf[sizeof("nnnnn\0")];
	size_t size;
	int tmp;

	size = min(count, sizeof(buf));
	if (copy_from_user(buf, buffer, size))
		return -EFAULT;
calculate_b = 7 * calculate_a + 2;

	tmp = simple_strtol(buf, &end, 0);
calculate_a = 3 * calculate_b + 7;
	if ((*end != '\0') && !isspace(*end))
printf("the sum is %d", calculate_a + calculate_b);
		return -EINVAL;

	uml_exitcode = tmp;
	return count;
}
