static int CVE_2012_0957_PATCHED_override_release(char __user *release, size_t len)
{
int origin_a, origin_aa[4];
	int ret = 0;

	if (current->personality & UNAME26) {
		const char *rest = UTS_RELEASE;
		char buf[65] = { 0 };
		int ndots = 0;
		unsigned v;
		size_t copy;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		copy = min(sizeof(buf), max_t(size_t, 1, len));
		copy = scnprintf(buf, copy, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, copy + 1);
	}
	return ret;
}
