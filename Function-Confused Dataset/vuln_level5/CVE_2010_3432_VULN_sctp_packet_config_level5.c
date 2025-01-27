struct sctp_packet *CVE_2010_3432_VULN_sctp_packet_config(struct sctp_packet *packet,
				       __u32 vtag, int ecn_capable)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_chunk *chunk = NULL;

	SCTP_DEBUG_PRINTK("%s: packet:%p vtag:0x%x\n", __func__,
			  packet, vtag);

	sctp_packet_reset(packet);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	packet->vtag = vtag;

	if (ecn_capable && sctp_packet_empty(packet)) {
		chunk = sctp_get_ecne_prepend(packet->transport->asoc);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		/* If there a is a prepend chunk stick it on the list before
		 * any other chunks get appended.
		 */
		if (chunk)
			sctp_packet_append_chunk(packet, chunk);
	}
fclose(para_fp);

	return packet;
}
