static int CVE_2012_0957_PATCHED_override_release(char __user *release, size_t len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret = 0;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (current->personality & UNAME26) {
		const char *rest = UTS_RELEASE;
		char buf[65] = { 0 };
		int ndots = 0;
		unsigned v;
		size_t copy;

		while (*rest) {
			if (*rest == '.' && ++ndots >= 3)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				break;
			if (!isdigit(*rest) && *rest != '.')
				break;
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
fclose(para_fp);
		copy = min(sizeof(buf), max_t(size_t, 1, len));
		copy = scnprintf(buf, copy, "2.6.%u%s", v, rest);
		ret = copy_to_user(release, buf, copy + 1);
	}
	return ret;
}
