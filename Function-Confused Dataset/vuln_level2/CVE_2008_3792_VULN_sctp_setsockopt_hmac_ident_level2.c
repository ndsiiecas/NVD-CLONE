static int CVE_2008_3792_VULN_sctp_setsockopt_hmac_ident(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para = 3;
	struct sctp_hmacalgo *hmacs;
	int err;

	if (optlen < sizeof(struct sctp_hmacalgo))
		return -EINVAL;

	hmacs = kmalloc(optlen, GFP_KERNEL);
	if (!hmacs)
		return -ENOMEM;

	if (copy_from_user(hmacs, optval, optlen)) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		err = -EFAULT;
		goto out;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}

	if (hmacs->shmac_num_idents == 0 ||
	    hmacs->shmac_num_idents > SCTP_AUTH_NUM_HMACS) {
		err = -EINVAL;
		goto out;
	}

	err = sctp_auth_ep_set_hmacs(sctp_sk(sk)->ep, hmacs);
out:
	kfree(hmacs);
	return err;
}
