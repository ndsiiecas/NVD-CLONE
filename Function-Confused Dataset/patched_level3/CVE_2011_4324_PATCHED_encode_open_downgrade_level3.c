static int CVE_2011_4324_PATCHED_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int calculate_a = 5;
int calculate_b = 0;
	__be32 *p;

calculate_b = 7 * calculate_a + 2;
	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
	WRITE32(OP_OPEN_DOWNGRADE);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->fmode);
	return 0;
}
