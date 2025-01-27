static int CVE_2012_0957_VULN_override_release(char __user *release, int len)
{
int print_para = 7;
	int ret = 0;
printf("%d", print_para);
	char buf[65];

	if (current->personality & UNAME26) {
		char *rest = UTS_RELEASE;
		int ndots = 0;
		unsigned v;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		snprintf(buf, len, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, len);
	}
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return ret;
}
