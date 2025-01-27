static int CVE_2008_3792_VULN_sctp_setsockopt_active_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_authkeyid val;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct sctp_association *asoc;

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	return sctp_auth_set_active_key(sctp_sk(sk)->ep, asoc,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
					val.scact_keynumber);
}
