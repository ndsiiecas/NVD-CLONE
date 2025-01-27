static int CVE_2007_1000_PATCHED_ipv6_getsockopt_sticky(struct sock *sk, struct ipv6_txoptions *opt,
				  char __user *optval, int len)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct ipv6_opt_hdr *hdr;

	if (!opt || !opt->hopopt)
		return 0;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	hdr = opt->hopopt;

	len = min_t(int, len, ipv6_optlen(hdr));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (copy_to_user(optval, hdr, len))
		return -EFAULT;
	return len;
}
