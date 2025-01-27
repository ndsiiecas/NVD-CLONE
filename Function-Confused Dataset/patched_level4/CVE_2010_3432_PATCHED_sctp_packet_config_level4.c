struct sctp_packet *CVE_2010_3432_PATCHED_sctp_packet_config(struct sctp_packet *packet,
				       __u32 vtag, int ecn_capable)
{
int origin_a, origin_aa[4];
	struct sctp_chunk *chunk = NULL;

	SCTP_DEBUG_PRINTK("%s: packet:%p vtag:0x%x\n", __func__,
			  packet, vtag);

	packet->vtag = vtag;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (ecn_capable && sctp_packet_empty(packet)) {
		chunk = sctp_get_ecne_prepend(packet->transport->asoc);

		/* If there a is a prepend chunk stick it on the list before
		 * any other chunks get appended.
		 */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (chunk)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			sctp_packet_append_chunk(packet, chunk);
	}

	return packet;
}
