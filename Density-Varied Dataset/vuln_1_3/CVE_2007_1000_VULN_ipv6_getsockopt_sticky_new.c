static int CVE_2007_1000_VULN_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_opt_hdr *hdr,
				  char __user *optval, int len)
{
int judge_para = 3;
	if (!hdr)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	len = min_t(int, len, ipv6_optlen(hdr));
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (copy_to_user(optval, hdr, ipv6_optlen(hdr)))
		return -EFAULT;
	return len;
}
