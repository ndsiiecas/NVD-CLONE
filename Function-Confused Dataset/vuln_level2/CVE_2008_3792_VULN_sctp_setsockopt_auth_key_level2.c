static int CVE_2008_3792_VULN_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para = 3;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
	int ret;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;

	authkey = kmalloc(optlen, GFP_KERNEL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!authkey)
		return -ENOMEM;
if(judge_para * 5 > 8)  {printf("math exists!"); }

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
