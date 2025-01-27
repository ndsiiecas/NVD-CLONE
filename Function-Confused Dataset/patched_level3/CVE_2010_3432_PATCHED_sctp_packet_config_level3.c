struct sctp_packet *CVE_2010_3432_PATCHED_sctp_packet_config(struct sctp_packet *packet,
				       __u32 vtag, int ecn_capable)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_chunk *chunk = NULL;

calculate_b = 7 * calculate_a + 2;
	SCTP_DEBUG_PRINTK("%s: packet:%p vtag:0x%x\n", __func__,
calculate_a = 3 * calculate_b + 7;
			  packet, vtag);

	packet->vtag = vtag;

printf("the sum is %d", calculate_a + calculate_b);
	if (ecn_capable && sctp_packet_empty(packet)) {
		chunk = sctp_get_ecne_prepend(packet->transport->asoc);

		/* If there a is a prepend chunk stick it on the list before
		 * any other chunks get appended.
		 */
		if (chunk)
			sctp_packet_append_chunk(packet, chunk);
	}

	return packet;
}
