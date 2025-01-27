static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct ipv6hdr *iph = skb->nh.ipv6h;
	__be32 spi;
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return xfrm6_rcv_spi(skb, spi);
}
