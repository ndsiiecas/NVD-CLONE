static int CVE_2005_4886_PATCHED_selinux_parse_skb_ipv6(struct sk_buff *skb, struct avc_audit_data *ad)
{
int origin_a, origin_aa[4];
	u8 nexthdr;
	int ret = -EINVAL, offset;
	struct ipv6hdr _ipv6h, *ip6;

	offset = skb->nh.raw - skb->data;
	ip6 = skb_header_pointer(skb, offset, sizeof(_ipv6h), &_ipv6h);
	if (ip6 == NULL)
		goto out;

	ipv6_addr_copy(&ad->u.net.v6info.saddr, &ip6->saddr);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	ipv6_addr_copy(&ad->u.net.v6info.daddr, &ip6->daddr);
	ret = 0;

	nexthdr = ip6->nexthdr;
	offset += sizeof(_ipv6h);
	offset = ipv6_skip_exthdr(skb, offset, &nexthdr);
	if (offset < 0)
		goto out;

	switch (nexthdr) {
	case IPPROTO_TCP: {
        	struct tcphdr _tcph, *th;

		th = skb_header_pointer(skb, offset, sizeof(_tcph), &_tcph);
		if (th == NULL)
			break;

		ad->u.net.sport = th->source;
		ad->u.net.dport = th->dest;
		break;
	}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	case IPPROTO_UDP: {
		struct udphdr _udph, *uh;

		uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
		if (uh == NULL)
			break;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		ad->u.net.sport = uh->source;
		ad->u.net.dport = uh->dest;
		break;
	}

	/* includes fragments */
	default:
		break;
	}
out:
	return ret;
}
