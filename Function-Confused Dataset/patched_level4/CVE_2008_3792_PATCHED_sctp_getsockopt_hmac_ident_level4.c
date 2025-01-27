static int CVE_2008_3792_PATCHED_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int origin_a, origin_aa[4];
	struct sctp_hmacalgo  __user *p = (void __user *)optval;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct sctp_hmac_algo_param *hmacs;
	__u16 data_len = 0;
	u32 num_idents;

	if (!sctp_auth_enable)
		return -EACCES;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	data_len = ntohs(hmacs->param_hdr.length) - sizeof(sctp_paramhdr_t);

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (len < sizeof(struct sctp_hmacalgo) + data_len)
		return -EINVAL;

	len = sizeof(struct sctp_hmacalgo) + data_len;
	num_idents = data_len / sizeof(u16);

	if (put_user(len, optlen))
		return -EFAULT;
	if (put_user(num_idents, &p->shmac_num_idents))
		return -EFAULT;
	if (copy_to_user(p->shmac_idents, hmacs->hmac_ids, data_len))
		return -EFAULT;
	return 0;
}
