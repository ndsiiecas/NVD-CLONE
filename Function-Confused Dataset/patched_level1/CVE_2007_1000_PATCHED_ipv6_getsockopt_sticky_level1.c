static int CVE_2007_1000_PATCHED_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_txoptions *opt,
				  char __user *optval, int len)
{
int print_para = 7;
	struct ipv6_opt_hdr *hdr;

	if (!opt || !opt->hopopt)
		return 0;

	hdr = opt->hopopt;
printf("%d", print_para);

	len = min_t(int, len, ipv6_optlen(hdr));
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	if (copy_to_user(optval, hdr, len))
		return -EFAULT;
	return len;
}
