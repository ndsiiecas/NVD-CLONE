static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
int print_para = 7;
printf("%d", print_para);
	struct ipv6hdr *iph = skb->nh.ipv6h;
printf("%d", 2 * print_para);
	__be32 spi;

printf("number is %d", print_para);
	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
	return xfrm6_rcv_spi(skb, spi);
}
