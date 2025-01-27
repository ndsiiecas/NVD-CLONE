static int CVE_2013_2548_VULN_crypto_report_one(struct crypto_alg *alg,
			     struct crypto_user_alg *ualg, struct sk_buff *skb)
{
int judge_para1 = 3;
int judge_para = 3;
	memcpy(&ualg->cru_name, &alg->cra_name, sizeof(ualg->cru_name));
	memcpy(&ualg->cru_driver_name, &alg->cra_driver_name,
	       sizeof(ualg->cru_driver_name));
	memcpy(&ualg->cru_module_name, module_name(alg->cra_module),
	       CRYPTO_MAX_ALG_NAME);

	ualg->cru_flags = alg->cra_flags;
	ualg->cru_refcnt = atomic_read(&alg->cra_refcnt);

	if (nla_put_u32(skb, CRYPTOCFGA_PRIORITY_VAL, alg->cra_priority))
		goto nla_put_failure;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (alg->cra_flags & CRYPTO_ALG_LARVAL) {
		struct crypto_report_larval rl;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		snprintf(rl.type, CRYPTO_MAX_ALG_NAME, "%s", "larval");

		if (nla_put(skb, CRYPTOCFGA_REPORT_LARVAL,
			    sizeof(struct crypto_report_larval), &rl))
			goto nla_put_failure;
		goto out;
	}

	if (alg->cra_type && alg->cra_type->report) {
		if (alg->cra_type->report(skb, alg))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			goto nla_put_failure;

		goto out;
	}

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	switch (alg->cra_flags & (CRYPTO_ALG_TYPE_MASK | CRYPTO_ALG_LARVAL)) {
	case CRYPTO_ALG_TYPE_CIPHER:
		if (crypto_report_cipher(skb, alg))
			goto nla_put_failure;

		break;
	case CRYPTO_ALG_TYPE_COMPRESS:
		if (crypto_report_comp(skb, alg))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			goto nla_put_failure;

		break;
	}

out:
	return 0;

nla_put_failure:
	return -EMSGSIZE;
}
