static int CVE_2008_3792_VULN_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para = 3;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int ret;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	authkey = kmalloc(optlen, GFP_KERNEL);
	if (!authkey)
		return -ENOMEM;

	if (copy_from_user(authkey, optval, optlen)) {
		ret = -EFAULT;
		goto out;
	}

	asoc = sctp_id2assoc(sk, authkey->sca_assoc_id);
	if (!asoc && authkey->sca_assoc_id && sctp_style(sk, UDP)) {
		ret = -EINVAL;
		goto out;
	}

	ret = sctp_auth_set_key(sctp_sk(sk)->ep, asoc, authkey);
out:
	kfree(authkey);
	return ret;
}
