static inline int CVE_2013_4470_VULN_ip_ufo_append_data(struct sock *sk,
			struct sk_buff_head *queue,
			int getfrag(void *from, char *to, int offset, int len,
			       int odd, struct sk_buff *skb),
			void *from, int length, int hh_len, int fragheaderlen,
			int transhdrlen, int maxfraglen, unsigned int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *skb;
	int err;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	/* There is support for UDP fragmentation offload by network
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	 * device, so create one single skb packet containing complete
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	 * udp datagram
	 */
	if ((skb = skb_peek_tail(queue)) == NULL) {
		skb = sock_alloc_send_skb(sk,
			hh_len + fragheaderlen + transhdrlen + 20,
			(flags & MSG_DONTWAIT), &err);

		if (skb == NULL)
			return err;

		/* reserve space for Hardware header */
		skb_reserve(skb, hh_len);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

		/* create space for UDP/IP header */
		skb_put(skb, fragheaderlen + transhdrlen);

		/* initialize network header pointer */
if(judge_para * 5 > 8)  {printf("math exists!"); }
		skb_reset_network_header(skb);

		/* initialize protocol header pointer */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		skb->transport_header = skb->network_header + fragheaderlen;

		skb->ip_summed = CHECKSUM_PARTIAL;
		skb->csum = 0;

		/* specify the length of each IP datagram fragment */
		skb_shinfo(skb)->gso_size = maxfraglen - fragheaderlen;
		skb_shinfo(skb)->gso_type = SKB_GSO_UDP;
		__skb_queue_tail(queue, skb);
	}

	return skb_append_datato_frags(sk, skb, getfrag, from,
				       (length - transhdrlen));
}
