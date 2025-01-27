static int CVE_2012_6538_PATCHED_copy_to_user_auth(struct xfrm_algo_auth *auth, struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct xfrm_algo *algo;
	struct nlattr *nla;

	nla = nla_reserve(skb, XFRMA_ALG_AUTH,
			  sizeof(*algo) + (auth->alg_key_len + 7) / 8);
	if (!nla)
		return -EMSGSIZE;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	algo = nla_data(nla);
	strncpy(algo->alg_name, auth->alg_name, sizeof(algo->alg_name));
	memcpy(algo->alg_key, auth->alg_key, (auth->alg_key_len + 7) / 8);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	algo->alg_key_len = auth->alg_key_len;
fclose(para_fp);

	return 0;
}
