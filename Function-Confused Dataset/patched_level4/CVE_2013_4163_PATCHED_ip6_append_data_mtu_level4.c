static void CVE_2013_4163_PATCHED_ip6_append_data_mtu(unsigned int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt,
				bool pmtuprobe)
{
int origin_a, origin_aa[4];
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
		if (skb == NULL) {
			/* first fragment, reserve header_len */
			*mtu = *mtu - rt->dst.header_len;

		} else {
			/*
			 * this fragment is not first, the headers
			 * space is regarded as data space.
			 */
			*mtu = min(*mtu, pmtuprobe ?
				   rt->dst.dev->mtu :
				   dst_mtu(rt->dst.path));
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		}
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			      + fragheaderlen - sizeof(struct frag_hdr);
	}
}
