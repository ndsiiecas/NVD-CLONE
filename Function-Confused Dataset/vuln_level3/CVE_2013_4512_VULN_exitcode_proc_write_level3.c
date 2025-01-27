static ssize_t CVE_2013_4512_VULN_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int calculate_a = 5;
int calculate_b = 0;
	char *end, buf[sizeof("nnnnn\0")];
	int tmp;
calculate_b = 7 * calculate_a + 2;

	if (copy_from_user(buf, buffer, count))
		return -EFAULT;

	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;

calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	uml_exitcode = tmp;
	return count;
}
