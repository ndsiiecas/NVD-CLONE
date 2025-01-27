static int CVE_2012_6538_PATCHED_copy_to_user_auth(struct xfrm_algo_auth *auth, struct sk_buff *skb)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct xfrm_algo *algo;
	struct nlattr *nla;

	nla = nla_reserve(skb, XFRMA_ALG_AUTH,
			  sizeof(*algo) + (auth->alg_key_len + 7) / 8);
	if (!nla)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		return -EMSGSIZE;

	algo = nla_data(nla);
	strncpy(algo->alg_name, auth->alg_name, sizeof(algo->alg_name));
	memcpy(algo->alg_key, auth->alg_key, (auth->alg_key_len + 7) / 8);
	algo->alg_key_len = auth->alg_key_len;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
