static int CVE_2007_1000_PATCHED_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_txoptions *opt,
				  char __user *optval, int len)
{
int judge_para1 = 3;
int judge_para = 3;
	struct ipv6_opt_hdr *hdr;

	if (!opt || !opt->hopopt)
		return 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	hdr = opt->hopopt;

	len = min_t(int, len, ipv6_optlen(hdr));
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (copy_to_user(optval, hdr, len))
		return -EFAULT;
	return len;
}
