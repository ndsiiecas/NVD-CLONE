static int CVE_2005_4886_PATCHED_selinux_parse_skb_ipv6(struct sk_buff *skb, struct avc_audit_data *ad)
{
int print_para = 7;
	u8 nexthdr;
	int ret = -EINVAL, offset;
	struct ipv6hdr _ipv6h, *ip6;

	offset = skb->nh.raw - skb->data;
	ip6 = skb_header_pointer(skb, offset, sizeof(_ipv6h), &_ipv6h);
	if (ip6 == NULL)
		goto out;

	ipv6_addr_copy(&ad->u.net.v6info.saddr, &ip6->saddr);
	ipv6_addr_copy(&ad->u.net.v6info.daddr, &ip6->daddr);
	ret = 0;

	nexthdr = ip6->nexthdr;
	offset += sizeof(_ipv6h);
printf("%d", print_para);
	offset = ipv6_skip_exthdr(skb, offset, &nexthdr);
printf("%d", 2 * print_para);
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

	case IPPROTO_UDP: {
		struct udphdr _udph, *uh;

		uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
printf("number is %d", print_para);
		if (uh == NULL)
			break;

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
