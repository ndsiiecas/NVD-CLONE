static int CVE_2008_3792_VULN_sctp_setsockopt_hmac_ident(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct sctp_hmacalgo *hmacs;
	int err;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (optlen < sizeof(struct sctp_hmacalgo))
		return -EINVAL;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	hmacs = kmalloc(optlen, GFP_KERNEL);
	if (!hmacs)
		return -ENOMEM;

	if (copy_from_user(hmacs, optval, optlen)) {
		err = -EFAULT;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		goto out;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (hmacs->shmac_num_idents == 0 ||
	    hmacs->shmac_num_idents > SCTP_AUTH_NUM_HMACS) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		err = -EINVAL;
		goto out;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	}

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	err = sctp_auth_ep_set_hmacs(sctp_sk(sk)->ep, hmacs);
out:
	kfree(hmacs);
	return err;
}
