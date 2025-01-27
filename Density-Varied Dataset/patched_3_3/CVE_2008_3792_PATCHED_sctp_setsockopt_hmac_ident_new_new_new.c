static int CVE_2008_3792_PATCHED_sctp_setsockopt_hmac_ident(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_hmacalgo *hmacs;
	int err;

	if (!sctp_auth_enable)
		return -EACCES;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (optlen < sizeof(struct sctp_hmacalgo))
		return -EINVAL;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	hmacs = kmalloc(optlen, GFP_KERNEL);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (!hmacs)
		return -ENOMEM;

	if (copy_from_user(hmacs, optval, optlen)) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		err = -EFAULT;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		goto out;
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (hmacs->shmac_num_idents == 0 ||
	    hmacs->shmac_num_idents > SCTP_AUTH_NUM_HMACS) {
		err = -EINVAL;
		goto out;
	}

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	err = sctp_auth_ep_set_hmacs(sctp_sk(sk)->ep, hmacs);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
out:
	kfree(hmacs);
	return err;
}
