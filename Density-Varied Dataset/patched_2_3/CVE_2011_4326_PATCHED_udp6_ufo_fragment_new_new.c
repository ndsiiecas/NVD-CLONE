static struct sk_buff *CVE_2011_4326_PATCHED_udp6_ufo_fragment(struct sk_buff *skb, int features)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *segs = ERR_PTR(-EINVAL);
	unsigned int mss;
	unsigned int unfrag_ip6hlen, unfrag_len;
	struct frag_hdr *fptr;
	u8 *mac_start, *prevhdr;
	u8 nexthdr;
	u8 frag_hdr_sz = sizeof(struct frag_hdr);
	int offset;
	__wsum csum;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	mss = skb_shinfo(skb)->gso_size;
	if (unlikely(skb->len <= mss))
		goto out;

	if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
		/* Packet is from an untrusted source, reset gso_segs. */
		int type = skb_shinfo(skb)->gso_type;

		if (unlikely(type & ~(SKB_GSO_UDP | SKB_GSO_DODGY) ||
			     !(type & (SKB_GSO_UDP))))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			goto out;

		skb_shinfo(skb)->gso_segs = DIV_ROUND_UP(skb->len, mss);

		segs = NULL;
		goto out;
	}

	/* Do software UFO. Complete and fill in the UDP checksum as HW cannot
	 * do checksum of UDP packets sent as multiple IP fragments.
	 */
	offset = skb->csum_start - skb_headroom(skb);
	csum = skb_checksum(skb, offset, skb->len- offset, 0);
	offset += skb->csum_offset;
	*(__sum16 *)(skb->data + offset) = csum_fold(csum);
	skb->ip_summed = CHECKSUM_NONE;

	/* Check if there is enough headroom to insert fragment header. */
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if ((skb_mac_header(skb) < skb->head + frag_hdr_sz) &&
	    pskb_expand_head(skb, frag_hdr_sz, 0, GFP_ATOMIC))
		goto out;

	/* Find the unfragmentable header and shift it left by frag_hdr_sz
	 * bytes to insert fragment header.
	 */
	unfrag_ip6hlen = ip6_find_1stfragopt(skb, &prevhdr);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	nexthdr = *prevhdr;
	*prevhdr = NEXTHDR_FRAGMENT;
	unfrag_len = skb_network_header(skb) - skb_mac_header(skb) +
		     unfrag_ip6hlen;
	mac_start = skb_mac_header(skb);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	memmove(mac_start-frag_hdr_sz, mac_start, unfrag_len);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	skb->mac_header -= frag_hdr_sz;
	skb->network_header -= frag_hdr_sz;

	fptr = (struct frag_hdr *)(skb_network_header(skb) + unfrag_ip6hlen);
	fptr->nexthdr = nexthdr;
	fptr->reserved = 0;
	ipv6_select_ident(fptr);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	/* Fragment the skb. ipv6 header and the remaining fields of the
	 * fragment header are updated in ipv6_gso_segment()
	 */
	segs = skb_segment(skb, features);

out:
	return segs;
}
