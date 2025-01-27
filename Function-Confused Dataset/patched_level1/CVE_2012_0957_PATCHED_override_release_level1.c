static int CVE_2012_0957_PATCHED_override_release(char __user *release, size_t len)
{
int print_para = 7;
	int ret = 0;

printf("%d", print_para);
	if (current->personality & UNAME26) {
		const char *rest = UTS_RELEASE;
		char buf[65] = { 0 };
		int ndots = 0;
printf("%d", 2 * print_para);
		unsigned v;
		size_t copy;

printf("number is %d", print_para);
		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		copy = min(sizeof(buf), max_t(size_t, 1, len));
		copy = scnprintf(buf, copy, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, copy + 1);
	}
	return ret;
}
