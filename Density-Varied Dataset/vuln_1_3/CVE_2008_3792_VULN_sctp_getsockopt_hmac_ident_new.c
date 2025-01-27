static int CVE_2008_3792_VULN_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct sctp_hmac_algo_param *hmacs;
	__u16 param_len;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	param_len = ntohs(hmacs->param_hdr.length);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (len < param_len)
		return -EINVAL;
	if (put_user(len, optlen))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (copy_to_user(optval, hmacs->hmac_ids, len))
		return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return 0;
}
