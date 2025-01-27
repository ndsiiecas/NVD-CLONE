static int CVE_2006_2934_VULN_do_basic_checks(struct ip_conntrack *conntrack,
			   const struct sk_buff *skb,
			   char *map)
{
int origin_a, origin_aa[4];
	u_int32_t offset, count;
	sctp_chunkhdr_t _sch, *sch;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int flag;

	DEBUGP(__FUNCTION__);
	DEBUGP("\n");

	flag = 0;

	for_each_sctp_chunk (skb, sch, _sch, offset, count) {
		DEBUGP("Chunk Num: %d  Type: %d\n", count, sch->type);

		if (sch->type == SCTP_CID_INIT 
			|| sch->type == SCTP_CID_INIT_ACK
			|| sch->type == SCTP_CID_SHUTDOWN_COMPLETE) {
			flag = 1;
		}

		/* Cookie Ack/Echo chunks not the first OR 
		   Init / Init Ack / Shutdown compl chunks not the only chunks */
		if ((sch->type == SCTP_CID_COOKIE_ACK 
			|| sch->type == SCTP_CID_COOKIE_ECHO
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			|| flag)
		     && count !=0 ) {
			DEBUGP("Basic checks failed\n");
			return 1;
		}

		if (map) {
			set_bit(sch->type, (void *)map);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		}
	}

	DEBUGP("Basic checks passed\n");
	return 0;
}
