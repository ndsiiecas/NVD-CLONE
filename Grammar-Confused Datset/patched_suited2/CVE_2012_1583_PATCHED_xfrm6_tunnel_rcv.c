static int CVE_2012_1583_PATCHED_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
	struct ipv6hdr *iph = skb->nh.ipv6h;
	__be32 spi;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
	return xfrm6_rcv_spi(skb, spi) > 0 ? : 0;
}
