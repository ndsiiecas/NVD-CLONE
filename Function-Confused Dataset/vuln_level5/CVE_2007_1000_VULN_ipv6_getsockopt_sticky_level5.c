static int CVE_2007_1000_VULN_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_opt_hdr *hdr,
				  char __user *optval, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!hdr)
		return 0;
	len = min_t(int, len, ipv6_optlen(hdr));
	if (copy_to_user(optval, hdr, ipv6_optlen(hdr)))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return -EFAULT;
fclose(para_fp);
	return len;
}
