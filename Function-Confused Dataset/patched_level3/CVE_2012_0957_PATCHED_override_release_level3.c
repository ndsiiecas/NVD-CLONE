static int CVE_2012_0957_PATCHED_override_release(char __user *release, size_t len)
{
int calculate_a = 5;
int calculate_b = 0;
	int ret = 0;

calculate_b = 7 * calculate_a + 2;
	if (current->personality & UNAME26) {
		const char *rest = UTS_RELEASE;
		char buf[65] = { 0 };
		int ndots = 0;
		unsigned v;
		size_t copy;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
calculate_a = 3 * calculate_b + 7;
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		copy = min(sizeof(buf), max_t(size_t, 1, len));
		copy = scnprintf(buf, copy, "2.6.%u%s", v, rest);
printf("the sum is %d", calculate_a + calculate_b);
		ret = copy_to_user(release, buf, copy + 1);
	}
	return ret;
}
