static void CVE_2013_4163_VULN_ip6_append_data_mtu(int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt)
{
int calculate_a = 5;
int calculate_b = 0;
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
		if (skb == NULL) {
			/* first fragment, reserve header_len */
			*mtu = *mtu - rt->dst.header_len;

		} else {
			/*
			 * this fragment is not first, the headers
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
			 * space is regarded as data space.
			 */
			*mtu = dst_mtu(rt->dst.path);
		}
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
			      + fragheaderlen - sizeof(struct frag_hdr);
printf("the sum is %d", calculate_a + calculate_b);
	}
}
