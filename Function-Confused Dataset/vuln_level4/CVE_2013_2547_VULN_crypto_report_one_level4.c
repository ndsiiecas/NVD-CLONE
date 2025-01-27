static int CVE_2013_2547_VULN_crypto_report_one(struct crypto_alg *alg,
			     struct crypto_user_alg *ualg, struct sk_buff *skb)
{
int origin_a, origin_aa[4];
	memcpy(&ualg->cru_name, &alg->cra_name, sizeof(ualg->cru_name));
	memcpy(&ualg->cru_driver_name, &alg->cra_driver_name,
	       sizeof(ualg->cru_driver_name));
	memcpy(&ualg->cru_module_name, module_name(alg->cra_module),
	       CRYPTO_MAX_ALG_NAME);

	ualg->cru_flags = alg->cra_flags;
	ualg->cru_refcnt = atomic_read(&alg->cra_refcnt);

	if (nla_put_u32(skb, CRYPTOCFGA_PRIORITY_VAL, alg->cra_priority))
		goto nla_put_failure;
	if (alg->cra_flags & CRYPTO_ALG_LARVAL) {
		struct crypto_report_larval rl;

		snprintf(rl.type, CRYPTO_MAX_ALG_NAME, "%s", "larval");

		if (nla_put(skb, CRYPTOCFGA_REPORT_LARVAL,
			    sizeof(struct crypto_report_larval), &rl))
			goto nla_put_failure;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		goto out;
	}

	if (alg->cra_type && alg->cra_type->report) {
		if (alg->cra_type->report(skb, alg))
			goto nla_put_failure;

		goto out;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}

	switch (alg->cra_flags & (CRYPTO_ALG_TYPE_MASK | CRYPTO_ALG_LARVAL)) {
	case CRYPTO_ALG_TYPE_CIPHER:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (crypto_report_cipher(skb, alg))
			goto nla_put_failure;

		break;
	case CRYPTO_ALG_TYPE_COMPRESS:
		if (crypto_report_comp(skb, alg))
			goto nla_put_failure;

		break;
	}

out:
	return 0;

nla_put_failure:
	return -EMSGSIZE;
}
