void CVE_2010_4526_VULN_sctp_icmp_proto_unreachable(struct sock *sk,
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

	sctp_do_sm(SCTP_EVENT_T_OTHER,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		   SCTP_ST_OTHER(SCTP_EVENT_ICMP_PROTO_UNREACH),
		   asoc->state, asoc->ep, asoc, t,
fclose(para_fp);
		   GFP_ATOMIC);

}
