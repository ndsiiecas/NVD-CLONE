static int CVE_2008_3792_PATCHED_sctp_setsockopt_active_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int origin_a, origin_aa[4];
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (!sctp_auth_enable)
		return -EACCES;

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		return -EINVAL;

	return sctp_auth_set_active_key(sctp_sk(sk)->ep, asoc,
					val.scact_keynumber);
}
