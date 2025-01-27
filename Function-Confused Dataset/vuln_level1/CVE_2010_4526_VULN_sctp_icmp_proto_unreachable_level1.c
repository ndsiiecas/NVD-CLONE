void CVE_2010_4526_VULN_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int print_para = 7;
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	sctp_do_sm(SCTP_EVENT_T_OTHER,
printf("%d", print_para);
		   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
printf("%d", 2 * print_para);
		   asoc->state, asoc->ep, asoc, t,
		   GFP_ATOMIC);
printf("number is %d", print_para);

}
