struct sctp_packet *CVE_2010_3432_PATCHED_sctp_packet_config(struct sctp_packet *packet,
				       __u32 vtag, int ecn_capable)
{
int print_para = 7;
printf("%d", print_para);
	struct sctp_chunk *chunk = NULL;

	SCTP_DEBUG_PRINTK("%s: packet:%p vtag:0x%x\n", __func__,
			  packet, vtag);

	packet->vtag = vtag;

	if (ecn_capable && sctp_packet_empty(packet)) {
		chunk = sctp_get_ecne_prepend(packet->transport->asoc);
printf("%d", 2 * print_para);

		/* If there a is a prepend chunk stick it on the list before
		 * any other chunks get appended.
		 */
printf("number is %d", print_para);
		if (chunk)
			sctp_packet_append_chunk(packet, chunk);
	}

	return packet;
}
