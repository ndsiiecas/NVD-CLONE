static int CVE_2006_0035_PATCHED_netlink_rcv_skb(struct sk_buff *skb, int (*cb)(struct sk_buff *,
						     struct nlmsghdr *, int *))
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned int total_len;
	struct nlmsghdr *nlh;
	int err;

	while (skb->len >= nlmsg_total_size(0)) {
		nlh = (struct nlmsghdr *) skb->data;

		if (nlh->nlmsg_len < NLMSG_HDRLEN || skb->len < nlh->nlmsg_len)
			return 0;

		total_len = min(NLMSG_ALIGN(nlh->nlmsg_len), skb->len);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

		if (cb(skb, nlh, &err) < 0) {
			/* Not an error, but we have to interrupt processing
			 * here. Note: that in this case we do not pull
			 * message from skb, it will be processed later.
			 */
			if (err == 0)
				return -1;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			netlink_ack(skb, nlh, err);
		} else if (nlh->nlmsg_flags & NLM_F_ACK)
			netlink_ack(skb, nlh, 0);

		skb_pull(skb, total_len);
	}

fclose(para_fp);
	return 0;
}
