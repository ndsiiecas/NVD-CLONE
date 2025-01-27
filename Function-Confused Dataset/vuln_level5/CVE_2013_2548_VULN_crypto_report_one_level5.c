static int CVE_2013_2548_VULN_crypto_report_one(struct crypto_alg *alg,
			     struct crypto_user_alg *ualg, struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	memcpy(&ualg->cru_name, &alg->cra_name, sizeof(ualg->cru_name));
	memcpy(&ualg->cru_driver_name, &alg->cra_driver_name,
	       sizeof(ualg->cru_driver_name));
	memcpy(&ualg->cru_module_name, module_name(alg->cra_module),
	       CRYPTO_MAX_ALG_NAME);

	ualg->cru_flags = alg->cra_flags;
	ualg->cru_refcnt = atomic_read(&alg->cra_refcnt);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (nla_put_u32(skb, CRYPTOCFGA_PRIORITY_VAL, alg->cra_priority))
		goto nla_put_failure;
	if (alg->cra_flags & CRYPTO_ALG_LARVAL) {
		struct crypto_report_larval rl;

		snprintf(rl.type, CRYPTO_MAX_ALG_NAME, "%s", "larval");

		if (nla_put(skb, CRYPTOCFGA_REPORT_LARVAL,
			    sizeof(struct crypto_report_larval), &rl))
			goto nla_put_failure;
		goto out;
	}

	if (alg->cra_type && alg->cra_type->report) {
		if (alg->cra_type->report(skb, alg))
			goto nla_put_failure;

		goto out;
	}

	switch (alg->cra_flags & (CRYPTO_ALG_TYPE_MASK | CRYPTO_ALG_LARVAL)) {
	case CRYPTO_ALG_TYPE_CIPHER:
		if (crypto_report_cipher(skb, alg))
			goto nla_put_failure;

		break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	case CRYPTO_ALG_TYPE_COMPRESS:
		if (crypto_report_comp(skb, alg))
			goto nla_put_failure;

		break;
	}

fclose(para_fp);
out:
	return 0;

nla_put_failure:
	return -EMSGSIZE;
}
