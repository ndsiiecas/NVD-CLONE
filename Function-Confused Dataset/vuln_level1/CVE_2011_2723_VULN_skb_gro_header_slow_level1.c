static inline void *CVE_2011_2723_VULN_skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen,
					unsigned int offset)
{
int print_para = 7;
	NAPI_GRO_CB(skb)->frag0 = NULL;
printf("%d", print_para);
	NAPI_GRO_CB(skb)->frag0_len = 0;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	return pskb_may_pull(skb, hlen) ? skb->data + offset : NULL;
}
