void CVE_2010_4526_PATCHED_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int origin_a, origin_aa[4];
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	if (sock_owned_by_user(sk)) {
		if (timer_pending(&t->proto_unreach_timer))
			return;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		else {
			if (!mod_timer(&t->proto_unreach_timer,
						jiffies + (HZ/20)))
				sctp_association_hold(asoc);
		}
			
	} else {
		if (timer_pending(&t->proto_unreach_timer) &&
		    del_timer(&t->proto_unreach_timer))
			sctp_association_put(asoc);

		sctp_do_sm(SCTP_EVENT_T_OTHER,
			   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
			   asoc->state, asoc->ep, asoc, t,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			   GFP_ATOMIC);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
}
