static void CVE_2013_4163_PATCHED_ip6_append_data_mtu(unsigned int *mtu,
				int *maxfraglen,
				unsigned int fragheaderlen,
				struct sk_buff *skb,
				struct rt6_info *rt,
				bool pmtuprobe)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	if (!(rt->dst.flags & DST_XFRM_TUNNEL)) {
		if (skb == NULL) {
			/* first fragment, reserve header_len */
			*mtu = *mtu - rt->dst.header_len;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		} else {
			/*
			 * this fragment is not first, the headers
			 * space is regarded as data space.
			 */
			*mtu = min(*mtu, pmtuprobe ?
				   rt->dst.dev->mtu :
				   dst_mtu(rt->dst.path));
		}
fclose(para_fp);
		*maxfraglen = ((*mtu - fragheaderlen) & ~7)
			      + fragheaderlen - sizeof(struct frag_hdr);
	}
}
