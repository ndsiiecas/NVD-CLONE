static int CVE_2008_3792_PATCHED_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
	int ret;

	if (!sctp_auth_enable)
		return -EACCES;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;

	authkey = kmalloc(optlen, GFP_KERNEL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!authkey)
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -ENOMEM;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (copy_from_user(authkey, optval, optlen)) {
		ret = -EFAULT;
		goto out;
	}

	asoc = sctp_id2assoc(sk, authkey->sca_assoc_id);
	if (!asoc && authkey->sca_assoc_id && sctp_style(sk, UDP)) {
		ret = -EINVAL;
		goto out;
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	ret = sctp_auth_set_key(sctp_sk(sk)->ep, asoc, authkey);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
out:
	kfree(authkey);
	return ret;
}
