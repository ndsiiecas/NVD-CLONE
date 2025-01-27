static int CVE_2012_0957_VULN_override_release(char __user *release, int len)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret = 0;
	char buf[65];

calculate_b = 7 * calculate_a + 2;
	if (current->personality & UNAME26) {
		char *rest = UTS_RELEASE;
		int ndots = 0;
		unsigned v;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
				break;
calculate_a = 3 * calculate_b + 7;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		snprintf(buf, len, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, len);
printf("the sum is %d", calculate_a + calculate_b);
	}
	return ret;
}
