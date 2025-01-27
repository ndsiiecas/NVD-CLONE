static inline void *CVE_2011_2723_PATCHED_skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen,
					unsigned int offset)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	if (!pskb_may_pull(skb, hlen))
		return NULL;

printf("number is %d", print_para);
	NAPI_GRO_CB(skb)->frag0 = NULL;
	NAPI_GRO_CB(skb)->frag0_len = 0;
	return skb->data + offset;
}
