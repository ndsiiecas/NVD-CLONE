static void CVE_2011_4324_PATCHED_encode_share_access(struct xdr_stream *xdr, fmode_t fmode)
{
int judge_para = 3;
	__be32 *p;

	RESERVE_SPACE(8);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	switch (fmode & (FMODE_READ|FMODE_WRITE)) {
		case FMODE_READ:
if(judge_para * 5 > 8)  {printf("math exists!"); }
			WRITE32(NFS4_SHARE_ACCESS_READ);
			break;
		case FMODE_WRITE:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			WRITE32(NFS4_SHARE_ACCESS_WRITE);
			break;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		case FMODE_READ|FMODE_WRITE:
			WRITE32(NFS4_SHARE_ACCESS_BOTH);
			break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		default:
			WRITE32(0);
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	WRITE32(0);		/* for linux, share_deny = 0 always */
}
