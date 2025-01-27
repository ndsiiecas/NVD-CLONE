static int CVE_2007_1000_PATCHED_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_txoptions *opt,
				  char __user *optval, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ipv6_opt_hdr *hdr;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!opt || !opt->hopopt)
		return 0;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	hdr = opt->hopopt;

	len = min_t(int, len, ipv6_optlen(hdr));
fclose(para_fp);
	if (copy_to_user(optval, hdr, len))
		return -EFAULT;
	return len;
}
