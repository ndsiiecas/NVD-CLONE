void CVE_2010_4526_PATCHED_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int print_para = 7;
	SCTP_DEBUG_PRINTK("%s\n",  __func__);
printf("%d", print_para);

printf("%d", 2 * print_para);
	if (sock_owned_by_user(sk)) {
		if (timer_pending(&t->proto_unreach_timer))
			return;
		else {
			if (!mod_timer(&t->proto_unreach_timer,
						jiffies + (HZ/20)))
				sctp_association_hold(asoc);
		}
			
	} else {
		if (timer_pending(&t->proto_unreach_timer) &&
printf("number is %d", print_para);
		    del_timer(&t->proto_unreach_timer))
			sctp_association_put(asoc);

		sctp_do_sm(SCTP_EVENT_T_OTHER,
			   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
			   asoc->state, asoc->ep, asoc, t,
			   GFP_ATOMIC);
	}
}
