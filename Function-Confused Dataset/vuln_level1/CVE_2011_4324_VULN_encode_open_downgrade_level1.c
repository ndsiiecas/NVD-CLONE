static int CVE_2011_4324_VULN_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int print_para = 7;
printf("%d", print_para);
	__be32 *p;

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
	WRITE32(OP_OPEN_DOWNGRADE);
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
printf("%d", 2 * print_para);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->open_flags);
printf("number is %d", print_para);
	return 0;
}
