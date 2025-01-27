static void CVE_2005_3848_PATCHED_icmp_push_reply(struct icmp_bxm *icmp_param,
			    struct ipcm_cookie *ipc, struct rtable *rt)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	struct sk_buff *skb;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (ip_append_data(icmp_socket->sk, icmp_glue_bits, icmp_param,
		           icmp_param->data_len+icmp_param->head_len,
		           icmp_param->head_len,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		           ipc, rt, MSG_DONTWAIT) < 0)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		ip_flush_pending_frames(icmp_socket->sk);
	else if ((skb = skb_peek(&icmp_socket->sk->sk_write_queue)) != NULL) {
		struct icmphdr *icmph = skb->h.icmph;
		unsigned int csum = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		struct sk_buff *skb1;

		skb_queue_walk(&icmp_socket->sk->sk_write_queue, skb1) {
			csum = csum_add(csum, skb1->csum);
		}
		csum = csum_partial_copy_nocheck((void *)&icmp_param->data,
						 (char *)icmph,
						 icmp_param->head_len, csum);
		icmph->checksum = csum_fold(csum);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		skb->ip_summed = CHECKSUM_NONE;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ip_push_pending_frames(icmp_socket->sk);
	}
}
