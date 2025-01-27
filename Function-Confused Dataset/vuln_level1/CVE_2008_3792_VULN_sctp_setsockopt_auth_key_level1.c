static int CVE_2008_3792_VULN_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int print_para = 7;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
	int ret;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;

printf("%d", print_para);
	authkey = kmalloc(optlen, GFP_KERNEL);
	if (!authkey)
		return -ENOMEM;

	if (copy_from_user(authkey, optval, optlen)) {
		ret = -EFAULT;
		goto out;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
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
