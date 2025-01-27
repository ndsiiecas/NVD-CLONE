static int CVE_2008_3792_VULN_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int origin_a, origin_aa[4];
	struct sctp_hmac_algo_param *hmacs;
	__u16 param_len;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	param_len = ntohs(hmacs->param_hdr.length);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (len < param_len)
		return -EINVAL;
	if (put_user(len, optlen))
		return -EFAULT;
	if (copy_to_user(optval, hmacs->hmac_ids, len))
		return -EFAULT;

	return 0;
}
