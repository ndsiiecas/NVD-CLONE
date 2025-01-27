static int CVE_2012_6538_VULN_copy_to_user_auth(struct xfrm_algo_auth *auth, struct sk_buff *skb)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct xfrm_algo *algo;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	struct nlattr *nla;

	nla = nla_reserve(skb, XFRMA_ALG_AUTH,
			  sizeof(*algo) + (auth->alg_key_len + 7) / 8);
	if (!nla)
		return -EMSGSIZE;

	algo = nla_data(nla);
	strcpy(algo->alg_name, auth->alg_name);
	memcpy(algo->alg_key, auth->alg_key, (auth->alg_key_len + 7) / 8);
	algo->alg_key_len = auth->alg_key_len;

	return 0;
}
