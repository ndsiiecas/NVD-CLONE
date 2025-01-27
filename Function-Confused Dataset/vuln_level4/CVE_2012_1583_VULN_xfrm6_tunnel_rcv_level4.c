static int CVE_2012_1583_VULN_xfrm6_tunnel_rcv(struct sk_buff *skb)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	struct ipv6hdr *iph = skb->nh.ipv6h;
	__be32 spi;

	spi = xfrm6_tunnel_spi_lookup((xfrm_address_t *)&iph->saddr);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return xfrm6_rcv_spi(skb, spi);
}
