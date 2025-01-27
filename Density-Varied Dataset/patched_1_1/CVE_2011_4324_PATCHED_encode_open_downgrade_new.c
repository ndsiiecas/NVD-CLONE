static int CVE_2011_4324_PATCHED_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int judge_para = 3;
	__be32 *p;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	WRITE32(OP_OPEN_DOWNGRADE);
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
	encode_share_access(xdr, arg->fmode);
	return 0;
}
