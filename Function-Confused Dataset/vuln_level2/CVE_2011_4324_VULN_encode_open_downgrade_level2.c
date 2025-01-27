static int CVE_2011_4324_VULN_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int judge_para = 3;
	__be32 *p;

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
	WRITE32(OP_OPEN_DOWNGRADE);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	encode_share_access(xdr, arg->open_flags);
	return 0;
}
