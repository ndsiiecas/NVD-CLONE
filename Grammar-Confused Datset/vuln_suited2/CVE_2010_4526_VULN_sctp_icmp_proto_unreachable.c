void CVE_2010_4526_VULN_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	sctp_do_sm(SCTP_EVENT_T_OTHER,
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
		   asoc->state, asoc->ep, asoc, t,
		   GFP_ATOMIC);

}
