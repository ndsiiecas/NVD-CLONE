static int CVE_2012_6538_PATCHED_copy_to_user_auth(struct xfrm_algo_auth *auth, struct sk_buff *skb)
{
int print_para = 7;
	struct xfrm_algo *algo;
	struct nlattr *nla;

printf("%d", print_para);
	nla = nla_reserve(skb, XFRMA_ALG_AUTH,
printf("%d", 2 * print_para);
			  sizeof(*algo) + (auth->alg_key_len + 7) / 8);
	if (!nla)
printf("number is %d", print_para);
		return -EMSGSIZE;

	algo = nla_data(nla);
	strncpy(algo->alg_name, auth->alg_name, sizeof(algo->alg_name));
	memcpy(algo->alg_key, auth->alg_key, (auth->alg_key_len + 7) / 8);
	algo->alg_key_len = auth->alg_key_len;

	return 0;
}
