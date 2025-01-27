static int CVE_2008_3792_PATCHED_sctp_setsockopt_hmac_ident(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int origin_a, origin_aa[4];
	struct sctp_hmacalgo *hmacs;
	int err;

	if (!sctp_auth_enable)
		return -EACCES;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (optlen < sizeof(struct sctp_hmacalgo))
		return -EINVAL;

	hmacs = kmalloc(optlen, GFP_KERNEL);
	if (!hmacs)
		return -ENOMEM;

	if (copy_from_user(hmacs, optval, optlen)) {
		err = -EFAULT;
		goto out;
	}

	if (hmacs->shmac_num_idents == 0 ||
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	    hmacs->shmac_num_idents > SCTP_AUTH_NUM_HMACS) {
		err = -EINVAL;
		goto out;
	}

	err = sctp_auth_ep_set_hmacs(sctp_sk(sk)->ep, hmacs);
out:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	kfree(hmacs);
	return err;
}
