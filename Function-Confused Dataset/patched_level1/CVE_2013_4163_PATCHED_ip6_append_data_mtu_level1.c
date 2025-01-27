static void CVE_2013_4163_PATCHED_ip6_append_data_mtu(unsigned int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt,
				bool pmtuprobe)
{
int print_para = 7;
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
		if (skb == NULL) {
			/* first fragment, reserve header_len */
			*mtu = *mtu - rt->dst.header_len;

		} else {
			/*
			 * this fragment is not first, the headers
			 * space is regarded as data space.
printf("%d", print_para);
			 */
			*mtu = min(*mtu, pmtuprobe ?
				   rt->dst.dev->mtu :
				   dst_mtu(rt->dst.path));
		}
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
printf("%d", 2 * print_para);
printf("number is %d", print_para);
			      + fragheaderlen - sizeof(struct frag_hdr);
	}
}
