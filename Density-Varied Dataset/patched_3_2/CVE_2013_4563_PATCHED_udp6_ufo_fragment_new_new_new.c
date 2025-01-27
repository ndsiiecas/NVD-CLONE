static struct sk_buff *CVE_2013_4563_PATCHED_udp6_ufo_fragment(struct sk_buff *skb,
	netdev_features_t features)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *segs = ERR_PTR(-EINVAL);
	unsigned int mss;
	unsigned int unfrag_ip6hlen, unfrag_len;
	struct frag_hdr *fptr;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	u8 *packet_start, *prevhdr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	u8 nexthdr;
	u8 frag_hdr_sz = sizeof(struct frag_hdr);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int offset;
	__wsum csum;
	int tnl_hlen;

	mss = skb_shinfo(skb)->gso_size;
	if (unlikely(skb->len <= mss))
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		goto out;

	if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
		/* Packet is from an untrusted source, reset gso_segs. */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		int type = skb_shinfo(skb)->gso_type;

		if (unlikely(type & ~(SKB_GSO_UDP |
				      SKB_GSO_DODGY |
				      SKB_GSO_UDP_TUNNEL |
				      SKB_GSO_GRE) ||
			     !(type & (SKB_GSO_UDP))))
			goto out;

		skb_shinfo(skb)->gso_segs = DIV_ROUND_UP(skb->len, mss);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		segs = NULL;
		goto out;
	}

	/* Do software UFO. Complete and fill in the UDP checksum as HW cannot
	 * do checksum of UDP packets sent as multiple IP fragments.
	 */
	offset = skb_checksum_start_offset(skb);
	csum = skb_checksum(skb, offset, skb->len - offset, 0);
	offset += skb->csum_offset;
	*(__sum16 *)(skb->data + offset) = csum_fold(csum);
	skb->ip_summed = CHECKSUM_NONE;

	/* Check if there is enough headroom to insert fragment header. */
	tnl_hlen = skb_tnl_header_len(skb);
		if (skb->mac_header < (tnl_hlen + frag_hdr_sz)) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (gso_pskb_expand_head(skb, tnl_hlen + frag_hdr_sz))
			goto out;
	}

	/* Find the unfragmentable header and shift it left by frag_hdr_sz
	 * bytes to insert fragment header.
	 */
	unfrag_ip6hlen = ip6_find_1stfragopt(skb, &prevhdr);
	nexthdr = *prevhdr;
	*prevhdr = NEXTHDR_FRAGMENT;
	unfrag_len = (skb_network_header(skb) - skb_mac_header(skb)) +
		     unfrag_ip6hlen + tnl_hlen;
	packet_start = (u8 *) skb->head + SKB_GSO_CB(skb)->mac_offset;
	memmove(packet_start-frag_hdr_sz, packet_start, unfrag_len);

	SKB_GSO_CB(skb)->mac_offset -= frag_hdr_sz;
	skb->mac_header -= frag_hdr_sz;
	skb->network_header -= frag_hdr_sz;

	fptr = (struct frag_hdr *)(skb_network_header(skb) + unfrag_ip6hlen);
	fptr->nexthdr = nexthdr;
	fptr->reserved = 0;
	ipv6_select_ident(fptr, (struct rt6_info *)skb_dst(skb));

	/* Fragment the skb. ipv6 header and the remaining fields of the
	 * fragment header are updated in ipv6_gso_segment()
	 */
	segs = skb_segment(skb, features);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

out:
	return segs;
}
