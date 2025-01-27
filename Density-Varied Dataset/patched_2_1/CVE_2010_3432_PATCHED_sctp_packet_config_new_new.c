struct sctp_packet *CVE_2010_3432_PATCHED_sctp_packet_config(struct sctp_packet *packet,
				       __u32 vtag, int ecn_capable)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_chunk *chunk = NULL;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	SCTP_DEBUG_PRINTK("%s: packet:%p vtag:0x%x\n", __func__,
			  packet, vtag);

	packet->vtag = vtag;

	if (ecn_capable && sctp_packet_empty(packet)) {
		chunk = sctp_get_ecne_prepend(packet->transport->asoc);

		/* If there a is a prepend chunk stick it on the list before
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		 * any other chunks get appended.
		 */
		if (chunk)
			sctp_packet_append_chunk(packet, chunk);
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return packet;
}
