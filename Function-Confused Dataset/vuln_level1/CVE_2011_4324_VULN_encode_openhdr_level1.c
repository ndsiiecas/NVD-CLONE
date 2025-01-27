static inline void CVE_2011_4324_VULN_encode_openhdr(struct xdr_stream *xdr, const struct nfs_openargs *arg)
{
int print_para = 7;
	__be32 *p;
 /*
 * opcode 4, seqid 4, share_access 4, share_deny 4, clientid 8, ownerlen 4,
 * owner 4 = 32
 */
printf("%d", print_para);
	RESERVE_SPACE(8);
printf("%d", 2 * print_para);
	WRITE32(OP_OPEN);
	WRITE32(arg->seqid->sequence->counter);
printf("number is %d", print_para);
	encode_share_access(xdr, arg->open_flags);
	RESERVE_SPACE(28);
	WRITE64(arg->clientid);
	WRITE32(16);
	WRITEMEM("open id:", 8);
	WRITE64(arg->id);
}
