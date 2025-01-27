static int CVE_2011_4324_VULN_encode_open_downgrade(struct xdr_stream *xdr, const struct nfs_closeargs *arg)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	__be32 *p;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	RESERVE_SPACE(4+NFS4_STATEID_SIZE+4);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	WRITE32(OP_OPEN_DOWNGRADE);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	WRITEMEM(arg->stateid->data, NFS4_STATEID_SIZE);
	WRITE32(arg->seqid->sequence->counter);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	encode_share_access(xdr, arg->open_flags);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
