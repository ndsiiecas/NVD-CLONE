static bool CVE_2014_8160_PATCHED_generic_new(struct nf_conn *ct, const struct sk_buff *skb,
			unsigned int dataoff, unsigned int *timeouts)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return nf_generic_should_process(nf_ct_protonum(ct));
}
