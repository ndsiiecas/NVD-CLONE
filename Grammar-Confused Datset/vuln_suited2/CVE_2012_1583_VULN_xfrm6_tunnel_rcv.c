static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
	struct ipv6hdr *iph = skb->nh.ipv6h;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	__be32 spi;

	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
	return xfrm6_rcv_spi(skb, spi);
}
