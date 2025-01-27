static int CVE_2005_4886_PATCHED_selinux_parse_skb_ipv6(struct sk_buff *skb, struct avc_audit_data *ad)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	u8 nexthdr;
	int ret = -EINVAL, offset;
	struct ipv6hdr _ipv6h, *ip6;

	offset = skb->nh.raw - skb->data;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	ip6 = skb_header_pointer(skb, offset, sizeof(_ipv6h), &_ipv6h);
	if (ip6 == NULL)
		goto out;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	ipv6_addr_copy(&ad->u.net.v6info.saddr, &ip6->saddr);
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
fclose(para_fp);
	}

	case IPPROTO_UDP: {
		struct udphdr _udph, *uh;

		uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
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
