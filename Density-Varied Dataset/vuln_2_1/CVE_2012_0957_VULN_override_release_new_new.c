static int CVE_2012_0957_VULN_override_release(char __user *release, int len)
{
int judge_para1 = 3;
int judge_para = 3;
	int ret = 0;
	char buf[65];

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (current->personality & UNAME26) {
		char *rest = UTS_RELEASE;
		int ndots = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		unsigned v;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
				break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		snprintf(buf, len, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, len);
	}
	return ret;
}
