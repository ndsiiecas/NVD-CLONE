void CVE_2010_4526_VULN_sctp_icmp_proto_unreachable(struct sock *sk,
			   struct sctp_association *asoc,
			   struct sctp_transport *t)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	SCTP_DEBUG_PRINTK("%s\n",  __func__);

	sctp_do_sm(SCTP_EVENT_T_OTHER,
		   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		   asoc->state, asoc->ep, asoc, t,
		   GFP_ATOMIC);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

}
