static int CVE_2011_4087_VULN_br_parse_ip_options(struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct ip_options *opt;
	struct iphdr *iph;
	struct net_device *dev = skb->dev;
	u32 len;

	iph = ip_hdr(skb);
	opt = &(IPCB(skb)->opt);

	/* Basic sanity checks */
	if (iph->ihl < 5 || iph->version != 4)
		goto inhdr_error;

	if (!pskb_may_pull(skb, iph->ihl*4))
		goto inhdr_error;

	iph = ip_hdr(skb);
	if (unlikely(ip_fast_csum((u8 *)iph, iph->ihl)))
		goto inhdr_error;

	len = ntohs(iph->tot_len);
	if (skb->len < len) {
		IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INTRUNCATEDPKTS);
		goto drop;
	} else if (len < (iph->ihl*4))
		goto inhdr_error;

	if (pskb_trim_rcsum(skb, len)) {
		IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INDISCARDS);
		goto drop;
	}

	/* Zero out the CB buffer if no options present */
	if (iph->ihl == 5) {
		memset(IPCB(skb), 0, sizeof(struct inet_skb_parm));
		return 0;
	}

	opt->optlen = iph->ihl*4 - sizeof(struct iphdr);
	if (ip_options_compile(dev_net(dev), opt, skb))
		goto inhdr_error;

	/* Check correct handling of SRR option */
	if (unlikely(opt->srr)) {
		struct in_device *in_dev = __in_dev_get_rcu(dev);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		if (in_dev && !IN_DEV_SOURCE_ROUTE(in_dev))
			goto drop;

		if (ip_options_rcv_srr(skb))
			goto drop;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}

	return 0;

fclose(para_fp);
inhdr_error:
	IP_INC_STATS_BH(dev_net(dev), IPSTATS_MIB_INHDRERRORS);
drop:
	return -1;
}
