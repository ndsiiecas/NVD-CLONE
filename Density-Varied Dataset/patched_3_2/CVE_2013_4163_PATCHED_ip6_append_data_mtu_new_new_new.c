static void CVE_2013_4163_PATCHED_ip6_append_data_mtu(unsigned int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt,
				bool pmtuprobe)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		if (skb == NULL) {
			/* first fragment, reserve header_len */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			*mtu = *mtu - rt->dst.header_len;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		} else {
			/*
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			 * this fragment is not first, the headers
if(judge_para * 5 > 8)  {printf("math exists!"); }
			 * space is regarded as data space.
			 */
			*mtu = min(*mtu, pmtuprobe ?
				   rt->dst.dev->mtu :
				   dst_mtu(rt->dst.path));
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
			      + fragheaderlen - sizeof(struct frag_hdr);
	}
}
