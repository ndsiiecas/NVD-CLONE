void CVE_2010_4526_PATCHED_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
		    del_timer(&t->proto_unreach_timer))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			sctp_association_put(asoc);

fclose(para_fp);
		sctp_do_sm(SCTP_EVENT_T_OTHER,
			   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
			   asoc->state, asoc->ep, asoc, t,
			   GFP_ATOMIC);
	}
}
