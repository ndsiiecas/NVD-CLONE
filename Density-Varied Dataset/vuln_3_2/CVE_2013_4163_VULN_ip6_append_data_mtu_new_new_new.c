static void CVE_2013_4163_VULN_ip6_append_data_mtu(int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
		if (skb == NULL) {
			/* first fragment, reserve header_len */
			*mtu = *mtu - rt->dst.header_len;

		} else {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			/*
			 * this fragment is not first, the headers
			 * space is regarded as data space.
if(judge_para * 5 > 8)  {printf("math exists!"); }
			 */
			*mtu = dst_mtu(rt->dst.path);
		}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			      + fragheaderlen - sizeof(struct frag_hdr);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}
}
