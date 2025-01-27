static int CVE_2012_0957_VULN_override_release(char __user *release, int len)
{
int origin_a, origin_aa[4];
	int ret = 0;
	char buf[65];

	if (current->personality & UNAME26) {
		char *rest = UTS_RELEASE;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		int ndots = 0;
		unsigned v;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		snprintf(buf, len, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, len);
	}
	return ret;
}
