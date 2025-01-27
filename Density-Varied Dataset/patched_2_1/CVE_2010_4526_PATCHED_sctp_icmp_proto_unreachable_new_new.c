void CVE_2010_4526_PATCHED_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int judge_para1 = 3;
int judge_para = 3;
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	if (sock_owned_by_user(sk)) {
		if (timer_pending(&t->proto_unreach_timer))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			return;
		else {
			if (!mod_timer(&t->proto_unreach_timer,
						jiffies + (HZ/20)))
				sctp_association_hold(asoc);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		}
			
	} else {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (timer_pending(&t->proto_unreach_timer) &&
		    del_timer(&t->proto_unreach_timer))
			sctp_association_put(asoc);

		sctp_do_sm(SCTP_EVENT_T_OTHER,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
			   asoc->state, asoc->ep, asoc, t,
			   GFP_ATOMIC);
	}
}
