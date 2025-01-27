static inline void *CVE_2011_2723_PATCHED_skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen,
					unsigned int offset)
{
	if (!pskb_may_pull(skb, hlen))
		return NULL;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	NAPI_GRO_CB(skb)->frag0 = NULL;
	NAPI_GRO_CB(skb)->frag0_len = 0;
	return skb->data + offset;
}
