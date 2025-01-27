static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	struct ipv6hdr *iph = skb->nh.ipv6h;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	__be32 spi;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
	return xfrm6_rcv_spi(skb, spi);
}
