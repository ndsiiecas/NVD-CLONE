static int CVE_2012_1583_PATCHED_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
int print_para = 7;
	struct ipv6hdr *iph = skb->nh.ipv6h;
	__be32 spi;
printf("%d", print_para);

printf("%d", 2 * print_para);
	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
printf("number is %d", print_para);
	return xfrm6_rcv_spi(skb, spi) > 0 ? : 0;
}
