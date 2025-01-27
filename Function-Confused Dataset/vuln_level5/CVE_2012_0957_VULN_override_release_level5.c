static int CVE_2012_0957_VULN_override_release(char __user *release, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int ret = 0;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			rest++;
		}
		v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
		snprintf(buf, len, "2.6.%u%s", v, rest);
fclose(para_fp);
		ret = copy_to_user(release, buf, len);
	}
	return ret;
}
