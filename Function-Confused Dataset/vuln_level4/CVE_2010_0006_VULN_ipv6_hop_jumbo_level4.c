static int CVE_2010_0006_VULN_ipv6_hop_jumbo(struct sk_buff *skb, int optoff)
{
int origin_a, origin_aa[4];
	const unsigned char *nh = skb_network_header(skb);
	u32 pkt_len;
	struct net *net = dev_net(skb_dst(skb)->dev);

	if (nh[optoff + 1] != 4 || (optoff & 3) != 2) {
		LIMIT_NETDEBUG(KERN_DEBUG "CVE_2010_0006_VULN_ipv6_hop_jumbo: wrong jumbo opt length/alignment %d\n",
			       nh[optoff+1]);
		IP6_INC_STATS_BH(net, ipv6_skb_idev(skb),
				 IPSTATS_MIB_INHDRERRORS);
		goto drop;
	}

	pkt_len = ntohl(*(__be32 *)(nh + optoff + 2));
	if (pkt_len <= IPV6_MAXPLEN) {
		IP6_INC_STATS_BH(net, ipv6_skb_idev(skb),
				 IPSTATS_MIB_INHDRERRORS);
		icmpv6_param_prob(skb, ICMPV6_HDR_FIELD, optoff+2);
		return 0;
	}
	if (ipv6_hdr(skb)->payload_len) {
		IP6_INC_STATS_BH(net, ipv6_skb_idev(skb),
				 IPSTATS_MIB_INHDRERRORS);
		icmpv6_param_prob(skb, ICMPV6_HDR_FIELD, optoff);
		return 0;
	}

	if (pkt_len > skb->len - sizeof(struct ipv6hdr)) {
		IP6_INC_STATS_BH(net, ipv6_skb_idev(skb),
				 IPSTATS_MIB_INTRUNCATEDPKTS);
		goto drop;
	}

	if (pskb_trim_rcsum(skb, pkt_len + sizeof(struct ipv6hdr)))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		goto drop;

	return 1;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

drop:
	kfree_skb(skb);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
