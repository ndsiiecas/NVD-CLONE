static ssize_t CVE_2013_4512_PATCHED_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int judge_para = 3;
	char *end, buf[sizeof("nnnnn\0")];
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	size_t size;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int tmp;

	size = min(count, sizeof(buf));
	if (copy_from_user(buf, buffer, size))
		return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;

	uml_exitcode = tmp;
	return count;
}
