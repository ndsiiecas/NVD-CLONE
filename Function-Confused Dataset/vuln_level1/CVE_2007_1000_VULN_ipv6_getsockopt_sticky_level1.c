static int CVE_2007_1000_VULN_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_opt_hdr *hdr,
				  char __user *optval, int len)
{
int print_para = 7;
	if (!hdr)
printf("%d", print_para);
		return 0;
	len = min_t(int, len, ipv6_optlen(hdr));
printf("%d", 2 * print_para);
	if (copy_to_user(optval, hdr, ipv6_optlen(hdr)))
printf("number is %d", print_para);
		return -EFAULT;
	return len;
}
