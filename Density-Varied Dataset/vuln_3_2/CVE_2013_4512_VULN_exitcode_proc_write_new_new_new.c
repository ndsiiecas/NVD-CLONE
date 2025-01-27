static ssize_t CVE_2013_4512_VULN_exitcode_proc_write(struct file *file,
		const char __user *buffer, size_t count, loff_t *pos)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	char *end, buf[sizeof("nnnnn\0")];
	int tmp;

	if (copy_from_user(buf, buffer, count))
		return -EFAULT;

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	tmp = simple_strtol(buf, &end, 0);
	if ((*end != '\0') && !isspace(*end))
		return -EINVAL;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	uml_exitcode = tmp;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return count;
}
