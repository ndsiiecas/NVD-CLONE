void CVE_2010_4526_PATCHED_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int calculate_a = 5;
int calculate_b = 0;
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	if (sock_owned_by_user(sk)) {
		if (timer_pending(&t->proto_unreach_timer))
			return;
		else {
			if (!mod_timer(&t->proto_unreach_timer,
calculate_b = 7 * calculate_a + 2;
						jiffies + (HZ/20)))
				sctp_association_hold(asoc);
		}
calculate_a = 3 * calculate_b + 7;
			
	} else {
printf("the sum is %d", calculate_a + calculate_b);
		if (timer_pending(&t->proto_unreach_timer) &&
		    del_timer(&t->proto_unreach_timer))
			sctp_association_put(asoc);

		sctp_do_sm(SCTP_EVENT_T_OTHER,
			   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
			   asoc->state, asoc->ep, asoc, t,
			   GFP_ATOMIC);
	}
}
