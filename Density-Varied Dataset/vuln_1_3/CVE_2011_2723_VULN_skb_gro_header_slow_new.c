static inline void *CVE_2011_2723_VULN_skb_gro_header_slow(struct sk_buff *skb, unsigned int hlen,
					unsigned int offset)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	NAPI_GRO_CB(skb)->frag0 = NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	NAPI_GRO_CB(skb)->frag0_len = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return pskb_may_pull(skb, hlen) ? skb->data + offset : NULL;
}
