static bool CVE_2014_8160_PATCHED_generic_new(struct nf_conn *ct, const struct sk_buff *skb,
			unsigned int dataoff, unsigned int *timeouts)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return nf_generic_should_process(nf_ct_protonum(ct));
}
